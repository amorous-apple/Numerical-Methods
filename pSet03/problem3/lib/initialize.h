#ifndef INITIALIZE_H
#define INITIALIZE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

extern int size;

void def_size(int argc, char* argv);
double *allo_vec(int vec_size);
double *def_vec(int vec_size);

double *allo_mat(int mat_size);
double *def_mat(int mat_size);

#endif
