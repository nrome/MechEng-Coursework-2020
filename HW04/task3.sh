#!/usr/bin/env bash
#SBATCH --partition=XXXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run task3 w/ SLURM      #
#############################

module load anaconda
bootstrap_conda
conda activate pyXXX

#   n set to 7 inputs
for i in 10 11 12 13 14 15 16

do

    python task3.py $((2**i))

done

echo $HOSTNAME

## Deactivate environment with: conda deactivate ##