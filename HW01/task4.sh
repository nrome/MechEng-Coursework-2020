#!/usr/bin/env bash
#SBATCH --partition=XXXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run task4 w/ SLURM      #
#############################

echo $HOSTNAME

# $HOSTNAME > output.txt
# pwd >> output.txt
# date >> output.txt
# cat output.txt

