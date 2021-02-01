#!/usr/bin/env bash
#SBATCH --partition=XXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run task1 w/ SLURM      #
#############################

module load anaconda
bootstrap_conda
conda activate pyXXX

python task1.py /usr/local/MECHENG/hw05_sample.csv

## Deactivate environment with: conda deactivate ##