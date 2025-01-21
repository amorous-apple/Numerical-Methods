#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

extern int FUNC_ID;
extern int NUM_FUNCTIONS;
extern int MIN_INTERVALS;
extern int MAX_INTERVALS;

typedef struct {
    int numPoints;
    double (*fnctPtr) (double);
    double ptA;
    double ptB;
    double *dataX;
    double *dataY;
} Integral;

void init(int argc, char **argv);
void init_integral(Integral *I);
double *setXVals(Integral *I);
double *setYVals(Integral *I);

#endif 
