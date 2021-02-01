#include "sort.h"

// Suggest an array of 10 random values
int A[] = {2, 34, 3, 13, 55, 1, 8, 21, 5, 0};

int main() {

    // Output A[...] attributes
    for (int i = 0; i < 10; i++) {
        printf("%d  ", A[i]);
    }

    // Force line break
    printf("\n");

    // Output A[...] attributes w/ Bubble Sort
    int n_elements = sizeof(A) / sizeof(A[0]);
    sort(A, n_elements);
    
}