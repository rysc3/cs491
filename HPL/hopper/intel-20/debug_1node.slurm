#!/bin/bash

#SBATCH --job-name HPL_1node
#SBATCH --partition debug
#SBATCH --nodes 1
#SBATCH --ntasks-per-node 8
#SBATCH --mem 16GB
#SBATCH --output debug_1node.out
#SBATCH --error debug_1node.err

module load intel/20.0.4 hpl

export OMP_PROC_BIND=TRUE
export OMP_PLACES=cores
export OMP_NUM_THREADS=4
srun --mpi=pmi2 xhpl
