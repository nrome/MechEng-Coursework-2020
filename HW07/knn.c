//  --------------------
//  Function Body - K Nearest Neighbor Algorithm
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h> 
#include <math.h>   // fabs
#include "knn.h"

double* compute_distances(size_t n_features,
                          const double* train_instances,
                          size_t n_train,
                          const double* test_instance) {

    //  --------------------
    //  Define types
    //  --------------------

    //  Ptr to double
    double *train_instances, *test_instance;

    //  --------------------
    //  Initialize types
    //  --------------------

    size_t n_features = 5;
    train_instances = (double *)(malloc(n * sizeof(double))); 
    size_t n_train = 8;
    test_instance = (double *)(malloc(n * sizeof(double)));

    double distance = sqrt((n_features - n_train) * (n_features - n_train) + (*train_instances - *test_instance) * (*train_instances - *test_instance));
    printf("The distance is : %f", fabs(distance));
    return;



}

