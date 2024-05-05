#!/bin/bash 

#SBATCH -N 50
#SBATCH -p normal 
#SBATCH --exclusive 

#SBATCH --mail-type all 
#SBATCH --mail-user 5053288338@vtext.com

module load intel/20.0.4 hpl/2.3-dxmk

export OMP_PROC_BIND=TRUE
export OMP_PLACES=cores
# TODO @ryan might need to make 64 def.
export OMP_NUM_THREADS=8

echo $(date)
srun --mpi=pmi2 xhpl
echo $(date)
