#!/usr/bin/env bash
#SBATCH --partition=XXX
#SBATCH --time=0-0:40:00
#SBATCH --cpus-per-task=1

#############################
#   Run task2 w/ SLURM      #
#############################

#   n set to 7 inputs
for i in 5 6 7 8 9 10 11 12 13

do

    #   replaces independent 2^xx args
    ./task2 $((2**i))

done

echo $HOSTNAME