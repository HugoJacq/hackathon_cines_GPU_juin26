# hackathon_cines_GPU_juin26

## See the results

this [file](notes.md)

## Other

[Questions pour les ingé AMD](questions.md)

[Test case avec Basilisk](basilisk_test_case)

## Some results

> benchmarks can be seen [here](https://basilisk.fr/sandbox/hugoj/benchmark_cpu_gpu/bench_turbulence.png)
The reference is: OpenGL using RTX 4090

You can use the following tests cases:
- [turbulence.c](https://github.com/HugoJacq/sandbox/blob/master/benchmark_cpu_gpu/turbulence_benchmark.c), run with resolution as argument: `./turbulence 256`
- other examples from Basilisk website, for example the breaking of a wave [link](https://basilisk.fr/src/examples/breaking.c)

## Compile on Adastra (CPU)

This section describes how to compile a Basilisk source file, not how to compile
the `qcc` wrapper. If you want to generate the source file, it is much easier
to do it on your local machine than on the server. If you want to do everything
on the server, please see section below to compile `qcc`)

The workflow is as follow: 

i) generate source file `_main.c` from `main.c` using `qcc`
ii) copy the file on the HPC workdir
iii) compile on the HPC using the right modules and libs

Copy the source file [_turbulence_benchmark.c](_turbulence_benchmark.c) into a working directory on
Adastra. The code has been generated with:
```bash
/home/jacqhugo/basilisk/src/qcc -g -Wall -pipe -D_FORTIFY_SOURCE=2 -O2 -fopenmp -nolineno -disable-dimensions -source turbulence_benchmark.c
```

The compilation script is the following
```bash
module purge

# Version de l'environnement Cray
module load cpe/24.07

# Architecture cible : MI250X (gfx90a) + CPU Trento
# module load craype-accel-amd-gfx90a craype-x86-trento

# CPU seulement
module load craype-x86-trento

# Compilateur Cray (supporte OpenACC → AMD GPU)
module load PrgEnv-cray

# Librairies ROCm/HIP
module load amd-mixed # maybe not needed on CPU


BASILISK=/lus/work/CT1/c1916930/hjacquet/basilisk/src

NAME=turbulence_benchmark
cc -Wall --std=c99 -D_XOPEN_SOURCE=700 -D_GNU_SOURCE -O2 \
        -fopenmp \
        _$NAME.c -o $NAME.cpu \
        -lm
```

The run script is
```bash
#!/bin/bash

#SBATCH --account=hmg2840
#SBATCH --job-name=breaking
#SBATCH --constraint=MI250
#SBATCH --nodes=1
#SBATCH --exclusive
#SBATCH --time=00:10:00

module purge

# Version de l'environnement Cray
module load cpe/24.07

# Architecture cible : MI250X (gfx90a) + CPU Trento
# module load craype-accel-amd-gfx90a craype-x86-trento

# CPU seulement
module load craype-x86-trento

# Compilateur Cray (supporte OpenACC → AMD GPU)
module load PrgEnv-cray

# Librairies ROCm/HIP
module load amd-mixed

RES = 256

# run
srun turbulence.cpu $RES 2> log > out
```

## How to compile qcc on Adastra

Download Basilisk with darcs (see this [link](https://basilisk.fr/src/INSTALL))
or use the archive basilisk.tar.gz that I provide on this repo. 

Copy the `basilisk/src` onto Adastra
Copy this small script in the `src` directory
```bash
#!/bin/bash

module purge

# Environnement Cray de base
module load cpe/24.07

# Architecture CPU + GPU
module load craype-accel-amd-gfx90a craype-x86-trento

# Compilateur
module load PrgEnv-cray

# ROCm/HIP
module load amd-mixed

# OSMesa (pour les libs GL de Basilisk)
#module load paraview/5.13.0-osmesa

# GSL
#module load gsl/2.7.1


# Basilisk compilation
#export BASILISK=/lus/home/CT1/c1916930/hjacquet/work/basilisk
ln -s config.adastra config
make > logs.make
```

You now have the `qcc` wrapper available. It can be useful to export its
location:
```bash
echo 'BASILISK=$HOME/basilisk/src'
```


## Compile on Adastra (GPU)

Work to do: make the HIP/CUDA version into a HIP/ROCm

The HIP library is in `basilisk/src/grid/hip/hip.c`

## How to compile the gpu librairies on local machine

> Compile the base Basilisk with [link](https://basilisk.fr/src/INSTALL)

> Compile for GPU, OpenGL (see [link](https://basilisk.fr/src/grid/gpu/grid.h#installation))
```bash
sudo apt install libglfw3-dev
cd $BASILISK/grid/gpu
make
```

> Compile for GPU, Nvidia
```bash
apt install cuda-driver-toolkit
cd $BASILISK/grid/cuda
make
```
The compilation (you might need to modify the Makefile) command is
```bash
cc -I/home/jacqhugo/basilisk/src -I.. -DSINGLE_PRECISION -O2 -g -Wall -pipe -D_FORTIFY_SOURCE=2   -c -o cuda.o cuda.c
ar cr libbuda.a cuda.o
```


> Compile for GPU, HIP through Nvidia
```bash
apt install hipcc
apt install cuda-driver-toolkit # if not done already
cd $BASILISK/grid/hip
make
```

The compilation (you might need to modify the Makefile) command is
```bash
hipcc -I/home/jacqhugo/basilisk/src -I.. -DSINGLE_PRECISION -O2 -D__HIP_PLATFORM_NVIDIA__ -g -D_FORTIFY_SOURCE=2 -c -o hip.o hip.c
```
Note: here `hipcc` is not strictly needed, I should be ok with just include the
headers...

***Notes***

- if your GPU is recent, you may get this error:
```
(fragment shader):399: CUDA: nvrtc: error: invalid value for --gpu-architecture (-arch)
```
Then you need to modify cuda.c and hip.c to force an older
architecture

```
sprintf(arch, "--gpu-architecture=compute_89");

```
just after the architecture detection, so after the line
```
sprintf (arch, "--gpu-architecture=compute_%d%d", major, minor);
```

- make sure that the nvidia driver is updated
```
apt install nvidia-drivers
```


