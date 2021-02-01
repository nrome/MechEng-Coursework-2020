//  --------------------
//  C - compute_distances w/ K Nearest Neighbor 
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "knn.h" 

    /*  2.b wants us to generate any train_instances and test_instace.
        Run compute_distances on both, print 1-norm line by line for each train_instance   */

int main (int argc, char *argv[]) {

    //  --------------------
    //  Define types
    //  --------------------

    size_t n_features, n_train;
    double *train_instances, *test_instance;

    //  --------------------
    //  Initialize types
    //  --------------------

    size_t n_features = 5; 
    size_t n_train = 8;

    // Dynamic memory
    train_instances = (double *)(malloc(n * sizeof(double)));
    test_instance = (double *)(malloc(n * sizeof(double)));

    //  --------------------
    //  Compute_distances func
    //  --------------------

    compute_distances(n_features, train_instances, n_train, test_instance);

	return 0;

}