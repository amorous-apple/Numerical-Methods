#ifndef INIT_H
#define INIT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *method;
    char *function;
    double a;
    double b;
    int numPoints;
} Parameters;

extern Parameters params;

void init(int argc, char **argv);

#endif
