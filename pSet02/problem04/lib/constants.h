#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <complex.h>
#include <math.h>

typedef struct {
    double complex root;
    double complex change;
    int count;
} Results;

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
} Parameters;

extern Parameters params;
Parameters def_params(void);

extern const char* filename;

extern const int nmax;
extern const double error;

extern const int img_width;
extern const int img_height;

extern const double p1_x;
extern const double p1_y;
extern const double p2_x;
extern const double p2_y;

// extern double rangex;
// extern double rangey;
//
// extern double xstart;
// extern double xend;
// extern double ystart;
// extern double yend;
//
// extern double xstep;
// extern double ystep;
// extern int xStepCount;
// extern int yStepCount;
//
#endif
