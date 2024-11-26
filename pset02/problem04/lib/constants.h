#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <complex.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	double xstart;
	double xend;
	double ystart;
	double yend;

	double rangex;
	double rangey;
	double xstep;
	double ystep;
	int xStepCount;
	int yStepCount;

	int MAX_LINE_SIZE;
	int MAX_BUFFER_SIZE;
} Parameters;

typedef struct {
    double complex root;
    double complex change;
    int count;
} Results;

typedef struct {
    double realZ;
    double imagZ;
    double realFofz;
    double imagFofz;
    double count;
} Datavals;

extern Parameters params;
Parameters def_params(int argc, char* argv[]);

extern const char* filename;

extern const int nmax;
extern const double error;

extern const int img_width;
extern const int img_height;

extern const double p1_x;
extern const double p1_y;
extern const double p2_x;
extern const double p2_y;

#endif
