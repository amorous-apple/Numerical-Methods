#include "constants.h"

// The name of the data file to be written
const char* filename = "./data/fractal_data.csv";

// The maximum number of loops to be executed
const int nmax = 200;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-9;

// Defining the image width and height (in pixels)
const int img_width = 400;
const int img_height = 400;

// Defining the plotting range by choosing two points to define a rectangle
// (pick the bottom left and top right points as p1 and p2 respectively)
const double p1_x = -2;
const double p1_y = -2;
const double p2_x = 2;
const double p2_y = 2;

Parameters def_params(int argc, char* argv[]) {
    Parameters params;

    if (argc > 1) {
        if (argc != 5) {
            printf("Invalid number of arguments!\n");
            printf("Usage: ./calc_fractal <p1_x> <p1_y> <p2_x> <p2_y> \n");
            printf(
                "p1 should be the bottom left coordinate and p2 the top right "
                "coordinate for the field of view. \n");
            exit(EXIT_FAILURE);
        } else {
            params.xstart = strtod(argv[1], NULL);
            params.ystart = strtod(argv[2], NULL);
            params.xend = strtod(argv[3], NULL);
            params.yend = strtod(argv[4], NULL);
        }
    } else {
        params.xstart = p1_x;
        params.ystart = p1_y;
        params.xend = p2_x;
        params.yend = p2_y;
    }

    params.rangex = fabs(params.xend - params.xstart);
    params.rangey = fabs(params.yend - params.ystart);
    params.xstep = params.rangex / img_width;
    params.ystep = params.rangey / img_height;
    params.xStepCount = img_width;
    params.yStepCount = img_height;

    params.MAX_LINE_SIZE = 128;
    params.MAX_BUFFER_SIZE = (params.xStepCount + 1) * (params.yStepCount + 1) *
                             params.MAX_LINE_SIZE;

    return params;
}
