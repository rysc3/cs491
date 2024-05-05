#!/bin/bash

#SBATCH --job-name HPL_2nodes
#SBATCH --partition debug
#SBATCH --nodes 2
#SBATCH --ntasks-per-node 4
#SBATCH --mem 8GB
#SBATCH --output debug_2nodes.out
#SBATCH --error debug_2nodes.err

module load gcc/11.2.0-655h hpl

export OMP_PROC_BIND=TRUE
export OMP_PLACES=cores
export OMP_NUM_THREADS=4
srun --mpi=pmi2 xhpl
