//  --------------------
//  C - Matrix Product Multiple Cases
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matmul.h"

//  Known const as marcos
#define row 1024
#define col 1024
#define mat_product (row * col)

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    //  Ptr to double
    double *A, *B, *mmFunc1, *mmFunc2, *mmFunc3, *mmFunc4;

    //  For multiple time trials
    clock_t start_trial_1, end_trial_1,
            start_trial_2, end_trial_2,
            start_trial_3, end_trial_3,
            start_trial_4, end_trial_4;

    double  time_trial_1, cpu_time_1,
            time_trial_2, cpu_time_2,
            time_trial_3, cpu_time_3,
            time_trial_4, cpu_time_4;

    //  Generic loops
    unsigned int i, j;

    //  --------------------
    //  Initialize types
    //  --------------------

    size_t n = row; // Both row/col expand to 1024 by macro

    // Dynamic memory
    A = (double *)(malloc(mat_product * sizeof(double)));
    B = (double *)(malloc(mat_product * sizeof(double)));
    mmFunc1 = (double *)(malloc(sizeof(double)));
    mmFunc2 = (double *)(malloc(sizeof(double)));
    mmFunc3 = (double *)(malloc(sizeof(double)));
    mmFunc4 = (double *)(malloc(sizeof(double)));

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
    //  Time and output for mmFunc2 (mmul2)
    //  --------------------

    start_trial_2 = clock();
        mmFunc2 = mmul2(A, B, n);
    end_trial_2 = clock();

    //  Compute time 
    time_trial_2 = ((double) (end_trial_2 - start_trial_2)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_2 = time_trial_2 * 1000;

    //  Output mmFunc2 (mmul2)
    printf("mmul2 output: %f \n", *mmFunc2);
    //  Output mmFunc1 (mmul1) time
    printf("mmul2 CPU time: %f \n", cpu_time_2);

    //  --------------------
    //  Time and output for mmFunc3 (mmul3)
    //  --------------------

    start_trial_3 = clock();
        mmFunc3 = mmul3(A, B, n);
    end_trial_3 = clock();

    //  Compute time 
    time_trial_3 = ((double) (end_trial_3 - start_trial_3)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_3 = time_trial_3 * 1000;

    //  Output mmFunc3 (mmul3)
    printf("mmul3 output: %f \n", *mmFunc3);
    //  Output mmFunc3 (mmul3) time
    printf("mmul3 CPU time: %f \n", cpu_time_3);

    //  --------------------
    //  Time and output for mmFunc4 (mmul4)
    //  --------------------

    start_trial_4 = clock();
        mmFunc4 = mmul4(A, B, n);
    end_trial_4 = clock();

    //  Compute time 
    time_trial_4 = ((double) (end_trial_4 - start_trial_4)) / CLOCKS_PER_SEC;
    //  Convert time to milliseconds (1s = 1000ms)
    cpu_time_4 = time_trial_4 * 1000;

    //  Output mmFunc4 (mmul4)
    printf("mmul4 output: %f \n", *mmFunc4);
    //  Output mmFunc4 (mmul4) time
    printf("mmul4 CPU time: %f \n", cpu_time_4);

    //  --------------------
    //  Release memory
    //  --------------------

    free(A);
    free(B);

    /*  I'm uncertain if memory is set free properly b/c
        C memory is set in the function but a new
        allocation is set for mmFunc1..4   */

    free(mmFunc1);
    free(mmFunc2);
    free(mmFunc3);
    free(mmFunc4);

    return 0;

}