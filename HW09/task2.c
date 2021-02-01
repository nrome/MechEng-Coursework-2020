//  --------------------
//  C - Scaling Analysis for Matrix Multiplication
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matmul.h"

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    //  Ptr to double
    double *A, *B, *mmFunc1;

    //  For multiple time trials
    clock_t start_trial_1, end_trial_1;

    double  time_trial_1, cpu_time_1;

    //  Generic loops
    unsigned int i, j;

    //  --------------------
    //  Initialize types
    //  --------------------

    size_t n = atoi(argv[1]);

    // Dynamic memory
    A = (double *)(malloc(n * n * sizeof(double)));
    B = (double *)(malloc(n * n * sizeof(double)));
    mmFunc1 = (double *)(malloc(sizeof(double)));

    //  Append random attributes to A[...] and B[...] matricies
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            //  Float -- arithmetic -- for range of -1 to 1
            A[i * n + j] = (double)rand() / RAND_MAX * 2.0 - 1.0; // A ROW major order
            B[i * n + j] = (double)rand() / RAND_MAX * 2.0 - 1.0; // B ROW major order  
        }
    }

    //  --------------------
    //  Time and output for mmFunc1 (mmul1)
    //  --------------------

    start_trial_1 = clock();
        mmFunc1 = mmul1(A, B, n);
    end_trial_1 = clock();

    //  Compute time 
    time_trial_1 = ((double) (end_trial_1 - start_trial_1)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_1 = time_trial_1 * 1000;

    //  Output mmFunc1 (mmul1)
    printf("mmul1 output: %f \n", *mmFunc1);
    //  Output mmFunc1 (mmul1) time
    printf("mmul1 CPU time: %f \n", cpu_time_1);

 
    //  --------------------
    //  Release memory
    //  --------------------

    free(A);
    free(B);
    free(mmFunc1);

    return 0;

}