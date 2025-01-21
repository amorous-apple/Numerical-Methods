#ifndef INTEGRATORS_H
#define INTEGRATORS_H

#include <math.h>

#include "init.h"

double int_trap(Integral *I);
double int_simp38(Integral *I);

double calc_error(double integralVal);

#endif
