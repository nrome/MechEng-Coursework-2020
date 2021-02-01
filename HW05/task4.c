//  --------------------
//  C - Parse CSV file for fnorm function
//  --------------------

#include <stdio.h>
#include <stdlib.h> // For exit() function
#include <string.h>
#include "fnorm.h"

//  Known const as marcos
#define row 1000
#define col 1000
#define mat_product (row * col)

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define / initialize types
    //  --------------------

    double *A;
    char temp[mat_product];
    char *token[mat_product];
    int i, j, m = 0, n_rows = 0, n_cols = 0, trim = 1;

    //  Dynamic memory
    // temp = (char *)malloc(row * col * sizeof(char));
    A = (double *)malloc(mat_product * sizeof(double));

    //  Parse CSV file - 2nd argument command line chain
    FILE *sample_csv = fopen(argv[1], "r");

    //  --------------------
    //  Output 
    //  --------------------

    if (sample_csv == NULL) {
        perror("Can't open file.");
        exit(1);
    }

    while(fgets(temp, mat_product, sample_csv) != NULL) {
    
        token[m] = strtok(temp, ",");
        j = 0;

        while(token[m] != NULL) {
            i = (n_rows * n_cols) + j;
            A[i] = atof(token[m]);
            j++;
            if (trim != 0) { n_cols++; }
            token[m] = strtok(NULL, ",");
        }

        trim = 0;
        n_rows++;

    }

    //  printf("mat: %d rows, %d cols\n", n_rows, n_cols);
    printf("fnorm: %f \n", fnorm(A, n_rows, n_cols));

    fclose(sample_csv);

    //  --------------------
    //  Release memory
    //  --------------------

    //  free(temp);
    free(A);

    return 0;

}