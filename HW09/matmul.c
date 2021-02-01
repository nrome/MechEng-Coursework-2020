//  --------------------
//  Function Body
//  --------------------

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "matmul.h"

double* mmul1(const double* A, const double* B, const size_t n){

    //  Ptr to double  
    double *C;
    //  Generic loops
    unsigned int i, j, k;

    //  Dynamic memory
    C = (double *)(malloc(n * n * sizeof(double)));

    //  Matrix product C = AB
    for (i = 0; i < n; i++) // sweeps rows of C
        for (j = 0; j < n; j++) // sweeps cols of C
            for (k = 0; k < n; k++) // Report C in ROW major order
                C[i * n + j] += A[i * n + k] * B[k * n + j]; 
                // dot prod i/row A and j/col B 

    return C;
 
}
