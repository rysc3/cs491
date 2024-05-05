#!/bin/bash

#SBATCH --job-name HPL_test1
#SBATCH --partition debug
#SBATCH --nodes 1
#SBATCH --ntasks-per-node 4
#SBATCH --cpus-per-task 1
#SBATCH --mem 16GB
#SBATCH --output test1.out
#SBATCH --error test1.err

module load gcc/11.2.0-655h hpl

export OMP_PROC_BIND=TRUE
export OMP_PLACES=cores
export OMP_NUM_THREADS=4
srun xhpl
