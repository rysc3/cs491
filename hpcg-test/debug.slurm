#!/bin/bash

#SBATCH --partition debug 
#SBATCH --nodes 1
#SBATCH --ntasks-per-node 2

module load openmpi
module load intel/20.0.4 hpcg 

srun --mpi=pmi2 xhpcg
