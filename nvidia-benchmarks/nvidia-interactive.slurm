#!/bin/bash 

#SBATCH --job-name nvidia-interactive
#SBATCH -N 1
#SBATCH -p condo
#SBATCH --ntasks-per-node 1
#SBATCH -G 1
#SBATCH --mail-type none
#SBATCH --mail-user rscherbarth@unm.edu

module load singularity

CONT='/users/rdscher/CLASS/cs491/nvidia-benchmarks/hpc-benchmarks:24.03.sif'
MOUNT='/users/rdscher/CLASS/cs491/nvidia-benchmarks/'

srun -N 1 --cpu-bind none --mpi=pmix \
  --container-image="${CONT}" \
  --container-mounts="${MOUNT}" \
  --pty bash
