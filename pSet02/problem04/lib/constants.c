#include "constants.h"

// The name of the data file to be written
const char* filename = "./data/fractal_data.csv";

// The maximum number of loops to be executed
const int nmax = 200;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-9;

// Defining the image width and height (in pixels)
const int img_width = 1000;
const int img_height = 1000;

// Defining the plotting range by choosing two points to define a rectangle
// (pick the bottom left and top right points as p1 and p2 respectively)
const double p1_x = -2;
const double p1_y = -2;
const double p2_x = 2;
const double p2_y = 2;

Parameters def_params(void) {
    Parameters params;

    params.xstart = p1_x;
    params.xend = p2_x;
    params.ystart = p1_y;
    params.yend = p2_y;

    params.rangex = fabs(p2_x - p1_x);
    params.rangey = fabs(p2_y - p1_y);
    params.xstep = params.rangex / img_width;
    params.ystep = params.rangey / img_height;
    params.xStepCount = (int)(params.rangex / params.xstep);
    params.yStepCount = (int)(params.rangey / params.ystep);

    return params;
}
