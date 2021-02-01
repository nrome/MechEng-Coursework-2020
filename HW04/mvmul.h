//  --------------------
//  Header
//  --------------------

#ifndef MVMUL_H
#define MVMUL_H

#include <stddef.h>

//  Multiplies an n by n matrix A (stored row-major) by a vector
//  b and saves the resulting vector in c

//  --------------------
//  Function signature - function prototype
//  --------------------

void mvmul(const double *A, const double *b, double *c, size_t n);

#endif
