#ifndef INTEGRATORS_H
#define INTEGRATORS_H

#include <stdio.h>
#include <stdlib.h>

#include "init.h"

double **RK4(double (*fnctPtr)(double, double), double yInitial, double xStart,
             double xEnd, int numSteps);
double **Heun(double (*fnctPtr)(double, double), double yInitial, double xStart,
             double xEnd, int numSteps);
double **Adams(double (*fnctPtr)(double, double), double yInitial, double xStart,
              double xEnd, int numSteps);
double **AdamsMoulton(double (*fnctPtr)(double, double), double yInitial,
                      double xStart, double xEnd, int numSteps);
double **AdamsMoultonPredicted(double (*fnctPtr)(double, double), double yInitial,
                      double xStart, double xEnd, int numSteps);
#endif
