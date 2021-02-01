#!/usr/bin/env bash
#SBATCH --partition=XXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run task1 w/ SLURM      #
#############################

#   n set to 7 inputs
for i in 9 10 11 12 13 14

do

    #   replaces independent 2^xx args
    ./task1 $((2**i))

done

echo $HOSTNAME