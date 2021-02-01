#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Why do we include header guards - run once or multiple times?
#ifndef STRUCTS_H
#define STRUCTS_H

struct A {

    int i;
    // Anticipated output 2-4 bytes

    char c;
    // Anticipated output 1 byte

    double d;
    // Anticipated output floating-point type 8 bytes

};

struct B {

    int i;
    // Anticipated output 2-4 bytes

    double d;
    // Anticipated output floating-point type 8 bytes
    // Larger structure appends padding above and below

    char c;
    // Anticipated output 1 byte

};

#endif
