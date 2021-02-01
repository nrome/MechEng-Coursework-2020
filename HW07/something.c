//  --------------------
//  C - Resolve Merge Conflict
//  --------------------

#include <stdio.h>

#define N 8

int main(int argc, char* argv[]) {
    printf("Hello world!\n");   // main version of hello world line

    for (size_t i = 0; i < N; i++) {
        printf("%zu ", i+1);    // feature version of item printing line first loop
    }
    printf("\n");

    //  Sum feature start   ----------

    size_t sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += i;
    }
    printf("sum: %zu\n", sum);

    //  SUM feature end   ----------

    //  ACC feature start   ----------

    int acc = 0;
    for (int i = 0; i < N; i++) {
        if (i % 2) {
            acc += i;
        }
        else {
            acc -= i;
        }
    }
    printf("acc: %d\n", acc);
    
    //  ACC feature end   ----------

    return 0;
}
