#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int equation;
    double trueVal;
    double a;
    double b;
    double c;
    double d;
} Parameters;

extern Parameters params;

void init(int argc, char **argv);

#endif
