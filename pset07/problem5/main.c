#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "lib/init.h"
#include "lib/integrators.h"
#include "lib/utils_data.h"

int main(int argc, char **argv) {
    init(argc, argv);

    // Allocating memory to store the log of the error values and the log of the
    // h values
    double **ls_logE = malloc((MAX_INTERVALS + 1) * sizeof(double *));
    double *doubleArr =
        malloc((MAX_INTERVALS + 1) * NUM_FUNCTIONS * sizeof(double));
    for (int i = 0; i < MAX_INTERVALS + 1; i++) {
        ls_logE[i] = doubleArr + i * NUM_FUNCTIONS;
    }
    double *ls_logh = malloc((MAX_INTERVALS + 1) * sizeof(double));
    if (ls_logh == NULL || ls_logE == NULL || doubleArr == NULL) {
        perror("Error allocating memory to store logE or logh!\n");
        exit(EXIT_FAILURE);
    }

#pragma omp parallel
    {
        // Declaring and initializing an integral for each thread
        Integral I;
        init_integral(&I);

#pragma omp for
        for (int numPoints = MIN_INTERVALS; numPoints <= MAX_INTERVALS;
             numPoints++) {
            I.numPoints = numPoints;
            setXVals(&I);
            setYVals(&I);

            double integralVal_trap = int_trap(&I);
            double error_trap = calc_error(integralVal_trap);
            ls_logE[numPoints][0] = log(error_trap);
            // double logE_trap = 0.0;

            double integralVal_simp = int_simp38(&I);
            double error_simp = calc_error(integralVal_simp);
            ls_logE[numPoints][1] = log(error_simp);

            double h = (I.ptB - I.ptA) / (I.numPoints - 1);
            ls_logh[numPoints] = log(h);
        }
        free(I.dataX);
        free(I.dataY);
    }

    // for (int i = MIN_INTERVALS; i < MAX_INTERVALS; i++) {
    //     printf("numPointds: %d, logh: %lf, logE1: %lf, logE2: %lf\n", i,
    //            ls_logh[i], ls_logE[i][0], ls_logE[i][1]);
    // }

    data_write(ls_logh, ls_logE);
}
