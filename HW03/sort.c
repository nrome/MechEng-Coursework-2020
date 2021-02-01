#include "sort.h"

// Define Bubble Sort operation/model
void sort(int* A, size_t n_elements) {

    // Iterate over the array first
    for (int step = 0; step < n_elements - 1; ++step) {
        // Iterate for comparison
        for (int i = 0; i < n_elements - step - 1; ++i) {
      
            // Sort in ASC order
            if (A[i] > A[i + 1]) {
                // swap if greater at the ending
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
            }
        }
    }

    // Print out the sorted array
    for (int i = 0; i < n_elements; ++i) {
        printf("%d  ", A[i]);
    }

    // Force line break
    printf("\n");
    
}

