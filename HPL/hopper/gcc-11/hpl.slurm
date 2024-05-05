#!/bin/bash 

#SBATCH -N 4
#SBATCH --ntasks-per-node 32
#SBATCH -p general
#SBATCH --exclusive 

#SBATCH --mail-type all 
#SBATCH --mail-user 5053288338@vtext.com

module load gcc/11.2.0-655h hpl

export OMP_PROC_BIND=TRUE
export OMP_PLACES=cores
# TODO @ryan might need to make 64 def.
export OMP_NUM_THREADS=64

echo $(date)
srun --mpi=pmi2 xhpl
echo $(date)
