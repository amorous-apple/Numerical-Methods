#include <omp.h>
#include <stdio.h>

#include "lib/constants.h"
#include "lib/fOfZ.h"
#include "lib/solve_cnewton.h"
#include "lib/utils.h"
#include "utils.h"

Parameters params;

int main(void) {
    // Opening the file through utils.c
    FILE *pfile = opfile(filename);

    params = def_params();

    // Iterating through every pixel in the image using x and y coordinates
    // to represent real and imaginary numbers in the complex plane.
// Parallelizing the outer loop
#pragma omp parallel for
    for (int i = 0; i <= params.xStepCount; i++) {
        double x = params.xstart + i * params.xstep;

        // Creating a buffer to store all of the y-values of a column
        const int MAX_LINE_SIZE = 128;
        char collBuffer[params.yStepCount + 1][MAX_LINE_SIZE];

        for (int j = 0; j <= params.yStepCount; j++) {
            double y = params.ystart + j * params.ystep;

            // Declaring the starting position for the algorithm
            double complex zstart = x + y * I;

            Results result = solve_cnewton(zstart);

            double complex z = result.root;
            double count;
            if (result.count == 0) {
                count = 0;
            } else {
                count = log10(result.count);
            }
            double complex fofz = fz(z);

            // Storing into buffer
            snprintf(collBuffer[j], MAX_LINE_SIZE,
                     "%.12lf,%.12lf,%.12lf,%.12lf,%.12lf,%.12lf,%.4lf\n", x, y,
                     creal(z), cimag(z), creal(fofz), cimag(fofz), count);
        }
#pragma omp critical
        {
            for (int j = 0; j <= params.yStepCount; j++) {
                fprintf(pfile, "%s", collBuffer[j]);
            }
            fprintf(pfile, "\n");
        }
    }
    fclose(pfile);
}
