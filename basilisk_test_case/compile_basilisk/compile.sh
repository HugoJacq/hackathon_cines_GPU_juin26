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
module load paraview/5.13.0-osmesa

# GSL
module load gsl/2.7.1


# Basilisk compilation
export BASILISK=/lus/home/CT1/c1916930/hjacquet/work/basilisk
ln -s config.adastra config
make > logs.make
