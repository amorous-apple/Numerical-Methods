#include <omp.h>
#include <stdio.h>

#include "lib/constants.h"
#include "lib/def_buffer.h"
#include "lib/solve_cnewton.h"
#include "lib/utils.h"
#include "utils.h"

Parameters params;

int main(int argc, char *argv[]) {
    params = def_params(argc, argv);
    char *BigBuff = def_buffer();

    // printf("f(2) = %lf + %lfi", creal(fz(2)), cimag(fz(2)));

// Parallelizing the outer loop
#pragma omp parallel for
    for (int i = 0; i <= params.xStepCount; i++) {
        double x = params.xstart + i * params.xstep;

        for (int j = 0; j <= params.yStepCount; j++) {
            double y = params.ystart + j * params.ystep;

            // Declaring the starting position for the algorithm
            double complex zstart = x + y * I;
            Datavals data = def_data(zstart);

            int index =
                (i * (params.yStepCount + 1) + j) * params.MAX_LINE_SIZE;

            // Storing into buffer
            snprintf(&BigBuff[index], params.MAX_LINE_SIZE,
                     "%.12lf,%.12lf,%.12lf,%.12lf,%.12lf,%.12lf,%.4lf\n", x, y,
                     data.realZ, data.imagZ, data.realFofz, data.imagFofz,
                     data.count);
        }
        // int index_newline =
        //     (i + 1) * (params.yStepCount + 1) * params.MAX_LINE_SIZE;
        // // Write a newline after every set of y-vales for a given x
        // snprintf(&BigBuff[index_newline], 2 * sizeof(char), "\n");
    }
    FILE *pfile = opfile(filename);

    // Write buffer to file
    for (int i = 0; i <= params.xStepCount; i++) {
        for (int j = 0; j <= params.yStepCount; j++) {
            int index =
                (i * (params.yStepCount + 1) + j) * params.MAX_LINE_SIZE;
            fprintf(pfile, "%s", &BigBuff[index]);
        }
        // int index_newline = i * (params.yStepCount + 1) *
        // params.MAX_LINE_SIZE;
        fprintf(pfile, "\n");
    }
    free(BigBuff);
    fclose(pfile);
}
