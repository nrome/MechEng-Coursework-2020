//  --------------------
//  C - Evaluate Volatile Qualifier and use Stride
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//  Known const as marcos
#define kb 512
//  Convert to bytes and divide by 8 (for doubles)
#define bytes (kb * 1000) / 8
//  For Loop capacity
#define x 100

void test1(double* data, int elems, int stride) { // The test function

    int i;
    double result = 0.0;
    volatile double sink;

    for (i = 0; i < elems; i += stride) {
        result += data[i];
    }

    sink = result; /* So compiler doesn't optimize away the loop */

}

void test2(double* data, int elems, int stride) { // The test function

    int i;
    volatile double result = 0.0;

    for (i = 0; i < elems; i += stride) {
        result += data[i];
    }

}

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    double *data, sum1, *time_trial_1, cpu_time_1,
                  sum2, *time_trial_2, cpu_time_2;

    //  For multiple time trials
    clock_t start_trial_1, end_trial_1,
            start_trial_2, end_trial_2;

    //  Generic loops
    unsigned int i, j;

    //  --------------------
    //  Initialize types
    //  --------------------

    int elems = bytes; // bytes expands 512 KB * 1000 / 8 from macro

    int stride[] = { 1, 2, 4, 8, 11, 15, 17 }; // fill stride array

    //  Dynamic memory
    data = (double *)(malloc(elems * sizeof(double)));
    time_trial_1 = (double *)(malloc(x * sizeof(double)));
    time_trial_2 = (double *)(malloc(x * sizeof(double)));

    //  Append random attributes to data[...]
    for (i = 0; i < elems; i++) {
        //  Float -- arithmetic -- for range of -1 to 1
        data[i] = (double)rand() / RAND_MAX * 2.0 - 1.0; 
    }

    //  --------------------
    //  Time and output for test1 function
    //  --------------------

    printf("timing for test1: \n");

    for (int i = 0; i < 7; i++) {

        //  Warm up cache
        test1(data, elems, stride[i]);

        sum1 = 0;

        for (j = 0; j < x; j++) {
            
            start_trial_1 = clock();
                test1(data, elems, stride[i]);
            end_trial_1 = clock();

            //  Compute time 
            time_trial_1[j] = ((double) (end_trial_1 - start_trial_1)) / CLOCKS_PER_SEC * 1000;
            
            sum1 += time_trial_1[j];
        }

        // Avg. to account for array
        cpu_time_1 = sum1 / x;
        //  Output test1 time
        printf("%f ", cpu_time_1);
    }

    printf("\n");

    //  --------------------
    //  Time and output for test2 function
    //  --------------------

    printf("timing for test2: \n");

    for (int i = 0; i < 7; i++) {

        //  Warm up cache
        test1(data, elems, stride[i]);

        sum2 = 0;

        for (j = 0; j < x; j++) {
            
            start_trial_2 = clock();
                test2(data, elems, stride[i]);
            end_trial_2 = clock();

            //  Compute time 
            time_trial_2[j] = ((double) (end_trial_2 - start_trial_2)) / CLOCKS_PER_SEC * 1000;
            
            sum2 += time_trial_2[j];
        }

        // Avg. to account for array
        cpu_time_2 = sum2 / x;
        //  Output test2 time
        printf("%f ", cpu_time_2);
    }

    printf("\n");

    //  --------------------
    //  Release memory
    //  --------------------

    free(data);
    free(time_trial_1);
    free(time_trial_2);

    return 0;

}