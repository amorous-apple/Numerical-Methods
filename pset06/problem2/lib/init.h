#ifndef INIT_H
#define INIT_H

#include <stdlib.h>
#include <stdio.h>

typedef struct {
    char method;
    double xi;
    double xf;
} Parameters;

extern Parameters params;

void init(int argc, char **argv);

#endif
