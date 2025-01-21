#ifndef INTEGRATE_H
#define INTEGRATE_H

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "functions.h"
#include "init.h"

typedef double (*methodPtr) (double *funcArr, double a, double b, int numPoints,
                      double *error);

typedef struct {
    char *methodName;
    methodPtr method;
} MethodMap;

double *fillArr(double (*func)(double), double a, double b, int numPoints);
double calcInt_newton(double *funcArr, double a, double b, int numPoints,
                      double *error);
methodPtr getMethodPtr(char *methodName);
double chooseInt(char *methodName, double *funcArr, double a, double b,
                 int numPoints, double *error);

#endif
