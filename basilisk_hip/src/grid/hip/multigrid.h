#define GRIDNAME "Multigrid (hip)"
#define _CUDA 1
#define _HIP_AMD 1
#include "../gpu-multigrid.h"

/**
The autolink pragma links the AMD ROCm HIP libraries: `-lamdhip64 -lhiprtc`.
See the [Makefile]() for compilation of the corresponding `libhip.a` library. */

#pragma autolink -L$BASILISK/grid/hip -lhip -lamdhip64 -lhiprtc -L$BASILISK/grid/gpu -lerrors

static void hip_multigrid_methods()
{
  multigrid_methods();
  boundary_level = gpu_boundary_level;
}
