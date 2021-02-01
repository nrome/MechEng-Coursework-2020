#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Satisfy the DESC order for qsort injection
int int_sorter(const void *first_arg, const void *second_arg) {
    // cast the pointers to the right type
    int first = *(int *)first_arg;
    int second = *(int *)second_arg;
    // carry out the comparison
    if (first < second) {
        return 1;
    } else if (first == second) {
        return 0;
    } else {
        return -1;
    }
}

int main (int argc, char *argv[]) {

    // --------------------
    // Define types
    // --------------------

    // Index references
    int i;
    // String to int 
    int arg1 = atoi(argv[1]); // argv[0] is the program name
    // Dynamic memory 
    int *storageArray = (int *)malloc((arg1 + 1) * sizeof(int));

    if (argc != 2) {
        printf("Need one argument to play. \n");
        exit(1);
    }

    // --------------------
    // Presuming the command convetions: $ <executable-file> <input>
    // As prescribed by Lijing - tests will be invoked with ./task3 N
    // Validating *argv[1] checks the second command in said chain
    // -------------------- 
    
    if (isdigit(*argv[1])) {

        // Assign val from arg1 to storageArray
        for (int i = 0; i <= arg1; i++) {
            storageArray[i] = i;
            printf("%d ", storageArray[i]);
        }

        // force line break
        printf("\n");

        // Arrange storageArray attributes with qsort using int_sorter
        qsort(storageArray, arg1 + 1, sizeof(int), int_sorter);

        for (i = 0; i <= arg1; i++) {
            printf("%d ", storageArray[i]);
        }

        // force line break
        printf("\n");

        // release memory 
        free(storageArray);

    } else {
        // terminate
        exit(1);
    }

    return 0;

}