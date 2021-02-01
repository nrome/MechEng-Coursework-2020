#!/usr/bin/env bash
#SBATCH --partition=XXXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run FP with  SLURM      #
#############################

module load anaconda
bootstrap_conda
conda activate rXXX

Rscript RomeroN_FinalProj.R

## Deactivate environment with: conda deactivate ##