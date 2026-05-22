

module purge

# Version de l'environnement Cray
module load cpe/24.07

# Architecture cible : MI250X (gfx90a) + CPU Trento
module load craype-accel-amd-gfx90a craype-x86-trento

# Compilateur Cray (supporte OpenACC → AMD GPU)
module load PrgEnv-cray

# Librairies ROCm/HIP
module load amd-mixed

export MPICH_GPU_SUPPORT_ENABLED=1

# osmesa
#module load paraview/5.13.0-osmesa

# OpenGL
#module load gsl/2.7.1


NAME=breaking_nobview #gulf-stream


cc -Wall --std=c99 -D_XOPEN_SOURCE=700 $(gsl-config --cflags) -D_GNU_SOURCE -O2 \
	-fopenmp \
        _$NAME.c -o $NAME.gpu \
	-lm $(gsl-config --libs)

