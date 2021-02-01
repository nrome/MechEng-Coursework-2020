//  --------------------
//  C - sumArray1, sumArray2
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sumArray.h"

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    //  Ptr to double
    double *A, *sumFunc1, *sumFunc2;

    //  For multiple time trials
    clock_t start_trial_1, end_trial_1,
            start_trial_2, end_trial_2;
    double time_trial_1, time_trial_2;
    double cpu_time_1, cpu_time_2;

    //  Generic loops
    unsigned int i, j;

    //  --------------------
    //  Initialize types
    //  --------------------

    //  Take in second command argument
    size_t n = atoi(argv[1]);

    //  Dynamic memory
    A = (double *)(malloc(n * n * sizeof(double)));
    sumFunc1 = (double *)(malloc(sizeof(double)));
    sumFunc2 = (double *)(malloc(sizeof(double)));
 
    //  Append random attributes to A[...] matrix
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            //  Float -- arithmetic -- for range of -1 to 1
            A[i * n + j] = (double)rand() / RAND_MAX * 2.0 - 1.0;

    //  --------------------
    //  Time and output for sumFunc1 (sumArray1)
    //  --------------------

    start_trial_1 = clock();
        sumFunc1 = sumArray1(A, n);
    end_trial_1 = clock();

    //  Compute time 
    time_trial_1 = ((double) (end_trial_1 - start_trial_1)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_1 = time_trial_1 * 1000;

    //  Output sumFunc1 (sumArray1)
    printf("sumArray1 output: %f \n", *sumFunc1);
    //  Output sumFunc1 (sumArray1) time
    printf("sumArray1 CPU time: %f \n", cpu_time_1);

    //  --------------------
    //  Time and output for sumFunc2 (sumArray2)
    //  --------------------

    start_trial_2 = clock();
        sumFunc2 = sumArray2(A, n);
    end_trial_2 = clock();

    //  Compute time 
    time_trial_2 = ((double) (end_trial_2 - start_trial_2)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_2 = time_trial_2 * 1000;

    //  Output sumFunc2 (sumArray2)
    printf("sumArray2 output: %f \n", *sumFunc2);
    //  Output sumFunc2 (sumArray2) time
    printf("sumArray2 CPU time: %f \n", cpu_time_2);

    //  --------------------
    //  Release memory
    //  --------------------

    free(A);

    /*  I'm uncertain if memory is set free properly b/c
        sum memory is set in the function but a new
        allocation is set for sumFunc1 & sumFunc2   */

    free(sumFunc1);
    free(sumFunc2);

    return 0;

}