#!/bin/bash
#SBATCH --job-name hostname
#SBATCH --partition debug
#SBATCH --ntasks 1
#SBATCH --cpus-per-task 1
#SBATCH --time 0:02
#SBATCH --mail-type all
#SBATCH --mail-user 5053288338@vtext.com

hostname
