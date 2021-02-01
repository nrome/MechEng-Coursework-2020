//  --------------------
//  C - Matrix Vector Multiplication
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "mvmul.h"

/*  argc as num of strings pointed to by argv
    argc (argument count) and argv (argument vector)
    *argv[x] references command line chain placement */

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    //  Ptr to double
    double *A, *b, *c;
    //  For time
    clock_t start, end;
    double time;
    double cpu_time_used;
    //  Generic loops
    int x, y;

    //  --------------------
    //  Initialize types
    //  --------------------

    //  Convert string arg to type int
    /*  Unsigned data type infers size of obj and
        holds array -- invoked w/ sizeof --
        captures the second argument in command chain */
    size_t n = atoi(argv[1]);

    // Dynamic memory
    A = (double *)(malloc(n * n * sizeof(double)));
    b = (double *)(malloc(n * sizeof(double)));
    c = (double *)(malloc(n * sizeof(double)));

    // Append random attributes to A[...]
    for (x = 0; x < (n * n); x++)
        // Float -- arithmetic -- for range of -1 to 1
        A[x] = (double)rand() / RAND_MAX * 2.0 - 1.0;

    // Append attributes to b[...] and c[...]
    for (y = 0; y < n; y++) {
        b[y] = 1.0;
        c[y] = 0.0;
    }

    //  --------------------
    //  Time interval around MVM func
    //  --------------------

    start = clock();
        mvmul(A, b, c, n);
    end = clock();

    // Compute time
    time = ((double) (end - start)) / CLOCKS_PER_SEC;
    // Convert time to milliseconds (1s = 1000ms)
    cpu_time_used = time * 1000;

    //  --------------------
    //  Output
    //  --------------------

    // Output final attribute in c
    printf("Last c entry: %f \n", c[n-1]);

    // Output time
    printf("CPU time: %f \n", cpu_time_used);

    //  --------------------
    //  Release memory
    //  --------------------

    free(A);
    free(b);
    free(c);

    return 0;

}