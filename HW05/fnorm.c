//  --------------------
//  Function Body - Frobenius Norm
//  --------------------

#include<stdio.h>
#include<math.h>

double fnorm(double *A, size_t n_rows, size_t n_cols) {

    double output = 0;

    for(int i = 0; i < n_rows; ++i) {
        for(int j = 0; j < n_cols; ++j) {
            double val = * (A + (i * n_cols) + j);
            output += val * val;
        }
    }

    return sqrt(output);

}

