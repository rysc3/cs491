#!/bin/bash
#SBATCH --job-name strong_julia
#SBATCH --partition debug
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 1
#SBATCH --time 0:01
#SBATCH --output=julia_strong_%a.out
#SBATCH --array 1-7
##SBATCH --mail-user mfricke@unm.edu
#SBATCH --mail-type all
#SBATCH --mail-user rscherbarth@unm.edu

OUTPUT_PATH=juliaset_weak_$SLURM_ARRAY_TASK_ID.tga

SCALE_FACTOR=$((2 ** ($SLURM_ARRAY_TASK_ID-1)))

export OMP_NUM_THREADS=$SCALE_FACTOR
FRACTAL_HEIGHT=10000
FRACTAL_WIDTH=2000

echo Scale Factor: $SCALE_FACTOR
echo Number of Threads: $OMP_NUM_THREADS
echo FRACTAL_DIMS: $FRACTAL_HEIGHT x $FRACTAL_WIDTH

./juliaset $FRACTAL_HEIGHT $FRACTAL_WIDTH $OUTPUT_PATH

