#!/bin/bash 

#SBATCH --partition debug 
#SBATCH --job-name cs491 

echo $(date)
srun ./sse_add
echo $(date)
