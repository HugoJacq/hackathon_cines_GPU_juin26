# HIP/AMD ROCm Port for Basilisk GPU Backend - Technical Report

## Overview

This report documents the porting of Basilisk's GPU backend from NVIDIA CUDA/OpenGL to AMD ROCm using HIP (Heterogeneous-compute Interface for Portability). The target platform was AMD MI250X GPUs (gfx90a architecture).

## Background

The original Basilisk GPU code was designed for:
- OpenGL with GLSL shaders (primary)
- NVIDIA CUDA via NVRTC runtime compilation

The code was initially translated using `hipify-perl`, but required significant modifications to work correctly with AMD's HIPRTC (HIP Runtime Compilation).

---

## Issues Encountered and Resolutions

### Issue 1: Struct Initialization Syntax

**Error:**
```
error: expected '}'
Point{point.i+_i, ...}
```

**Cause:** HIP/AMD requires pure aggregate structs with brace initialization `{a,b}`, not constructor-style initialization `type(a,b)`.

**Resolution:** Changed struct initialization syntax and ensured all structs (Point, ivec2, vec2, vec3) are pure aggregates without constructors:
```c
// Before (CUDA style)
Point(point.i+_i, point.j+_j, ...)

// After (HIP/AMD compatible)
Point{point.i+_i, point.j+_j, ...}
```

---

### Issue 2: Device Function Visibility

**Error:**
```
error: call to __host__ function from __global__ function
```

**Cause:** Functions like `clamp`, `apply_bc`, boundary condition functions were not marked as device-callable.

**Resolution:** 
- Added `__host__ __device__` to helper functions like `clamp`
- Prepended `__device__` to function definitions in generated shader code for HIP/AMD:
```c
#if _HIP_AMD
  fs = str_append (fs, "\n__device__ ", f->data, "\n");
#else
  fs = str_append (fs, "\n", f->data, "\n");
#endif
```

---

### Issue 3: `__constant__` Variables Not Accessible via hipModuleGetGlobal

**Error:**
```
hip.c:374: HIP error: hipErrorNotFound
```

**Cause:** AMD HIPRTC does not export `__constant__` variables for runtime lookup via `hipModuleGetGlobal`. This is a fundamental difference from NVIDIA's NVRTC.

**Resolution:** Changed uniform declarations from `__constant__` to `__device__`:
```c
#if _HIP_AMD
  // Use __device__ for variables set via hipModuleGetGlobal + hipMemcpy
  "__device__ ivec2 csOrigin = {0,0};\n"
#else
  // CUDA/NVIDIA: use __constant__
  "__constant__ ivec2 csOrigin = {0,0};\n"
#endif
```

---

### Issue 4: `__managed__` Not Supported

**Error:**
```
error: unknown type name '__managed__'
```

**Cause:** HIPRTC does not support `__managed__` memory.

**Resolution:** Avoided `__managed__` entirely; used `__device__` variables with explicit memory copies.

---

### Issue 5: Float Literal Formatting

**Error:**
```
error: invalid digit 'f' in octal constant
const float X0 = 0f;
```

**Cause:** Using `%gf` format specifier produces `0f` for zero values, which is invalid C/C++ syntax (interpreted as octal).

**Resolution:** Used `%#.9gf` format specifier which forces a decimal point:
```c
// Before
snprintf (val, 63, " = %gf;\n", value);  // Produces "0f"

// After  
snprintf (val, 63, " = %#.9gf;\n", value);  // Produces "0.00000000f"
```

---

### Issue 6: HIPRTC Compiler Options

**Error:** Silent crash during reduction kernel compilation.

**Cause:** The reduction kernel used NVIDIA-specific compiler options (`--std=c++11`, `--use_fast_math`).

**Resolution:** Platform-specific compiler options:
```c
#ifdef __HIP_PLATFORM_AMD__
  const char* options[] = {
    arch,
    "--std=c++14",
    "-ffast-math"
  };
#else
  const char* options[] = {
    arch,
    "--std=c++11",
    "--use_fast_math"
  };
#endif
```

---

### Issue 7: Excessive Shader Recompilation

**Symptom:** 2682 shaders compiled vs expected ~65, causing extreme slowdown.

**Cause:** Initial approach embedded uniform values (dt, L0, etc.) as constants in shader code. Every value change triggered shader hash mismatch and recompilation.

**Resolution:** 
- Declared uniforms as `__device__` variables (not constants)
- Used `hipModuleGetGlobal` to get device addresses
- Copied values via `hipMemcpyAsync` before each kernel launch
- Removed uniform values from shader hash computation

---

### Issue 8: Race Condition with _data_ptr Initialization

**Symptom:** Horizontal stripe artifacts in output (visual corruption).

**Cause:** `_data_ptr` was being set from within the kernel by all threads:
```c
// Problematic approach - race condition
void kernel(float* _data_arg) {
    _data_ptr = _data_arg;  // All threads write, not visible across blocks
    ...
}
```

**Resolution:** Set `_data_ptr` via `hipMemcpyAsync` BEFORE kernel launch:
```c
// In finalize_shader:
HIP_CHECK (hipModuleGetGlobal(&shader->_data, &size, shader->module, "_data_ptr"));

// In post_setup_shader:
HIP_CHECK (hipMemcpyAsync ((void *)shader->_data, &ssbo, sizeof(ssbo), 
                           hipMemcpyHostToDevice, stream));

// Kernel no longer initializes _data_ptr
void kernel(float* /*unused*/) {
    // _data_ptr already set before launch
    ...
}
```

---

### Issue 9: HIP API Differences (Driver vs Runtime)

**Cause:** HIP on AMD uses Runtime API semantics, while HIP-on-CUDA uses Driver API semantics.

**Resolution:** Conditional API usage throughout:
```c
#ifdef __HIP_PLATFORM_AMD__
  HIP_CHECK (hipMemcpyAsync ((void *)location, data, size, hipMemcpyHostToDevice, stream));
#else
  HIP_CHECK (hipMemcpyHtoDAsync (location, data, size, stream));
#endif
```

---

## Summary of Key Code Changes

### Files Modified

1. **`src/grid/gpu/grid.h`**
   - Conditional struct definitions (pure aggregates for HIP)
   - `__device__` function annotations for HIP
   - Conditional uniform declarations (`__device__` vs `__constant__`)
   - Platform-specific `csOrigin`, `vsOrigin`, `vsScale` declarations
   - Modified kernel function signature for HIP

2. **`src/grid/hip/hip.c`**
   - Platform-specific HIPRTC compiler options
   - Enabled `hipModuleGetGlobal` for `__device__` variables on AMD
   - Added `hipMemcpyAsync` for uniform updates on AMD
   - Fixed reduction kernel compilation options

3. **`src/grid/hip/multigrid.h` and `cartesian.h`**
   - Added `#define _HIP_AMD 1` for compile-time detection

---

## Architecture Summary

The working HIP/AMD implementation uses this architecture:

1. **Uniform Variables**: Declared as `__device__` (not `__constant__`)
2. **Symbol Lookup**: `hipModuleGetGlobal` works for `__device__` variables
3. **Value Updates**: `hipMemcpyAsync` before kernel launch
4. **Data Pointer**: `_data_ptr` set via memcpy, not kernel initialization
5. **Kernel Arguments**: Still pass ssbo pointer (for compatibility) but don't use it for initialization

This avoids the HIPRTC limitation where `__constant__` symbols are not exported, while maintaining compatibility with the existing CUDA/NVIDIA code path.

---

## Build Instructions

### Prerequisites
- ROCm 7.2.0 or compatible version
- AMD GPU with gfx90a architecture (MI250X) or similar

### Compilation
```bash
# Build the HIP library
cd $BASILISK/grid/hip
make clean && make

# Compile a test case
module load rocm/7.2.0
$BASILISK/qcc -grid=hip/multigrid -DBENCHMARK=1 turbulence.c
hipcc --offload-arch=gfx90a _turbulence.c -o turbulence.hip \
    -L$BASILISK/grid/gpu -lerrors \
    -L$BASILISK/grid/hip -lhip -lhiprtc -lm
```

### Running
```bash
./turbulence.hip 512
```

---

## Performance Notes

The HIP/AMD implementation achieves comparable performance to the CUDA/NVIDIA version once the shader caching is working correctly (65 shader compilations instead of 2682).

Key performance considerations:
- Shader compilation happens at runtime on first use
- Uniform values are copied to device before each kernel launch
- The `hipMemcpyAsync` calls are asynchronous and overlap with computation

---

## Date
June 2026
