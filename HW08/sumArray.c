//  --------------------
//  Function Body
//  --------------------

//  See Lecture 18 slide 24 mat1D pattern and matrix mult

#include <stdio.h>
#include <stdlib.h>
#include "sumArray.h"

double* sumArray1(const double* A, const size_t n) {

    //  Ptr to double  
    double *sum;
    //  Generic loops
    unsigned int i, j;

    //  Dynamic memory
    sum = (double *)(malloc(sizeof(double)));

    //  Compute sum of elements
    *sum = 0.;
    for (i = 0; i < n; i++) // sweeps rows of A
        for (j = 0; j < n; j++) // sweeps cols of A
            *sum += A[i * n + j]; 

    return sum;

}

double* sumArray2(const double* A, const size_t n) {

    //  Ptr to double  
    double *sum;
    //  Generic loops
    unsigned int i, j;

    //  Dynamic memory
    sum = (double *)(malloc(sizeof(double)));

    //  Compute sum of elements
    *sum = 0.;
    for (j = 0; j < n; j++) // sweeps cols of A (sumArray1 swap)
        for (i = 0; i < n; i++) // sweeps rows of A (sumArray1 swap)
            *sum += A[i * n + j]; 

    return sum;

}
