#!/bin/bash

#SBATCH --account=hmg2840
#SBATCH --job-name=breaking
#SBATCH --constraint=MI250
#SBATCH --nodes=1
#SBATCH --exclusive
#SBATCH --time=00:10:00
#SBATCH --reservation=hackaton
#SBATCH --gpus-per-node=4


module purge

source $HOME/.env_bas

module list

RES=512
NAME=turbulence

# run
./turbulence.hip $RES 2> log > out


