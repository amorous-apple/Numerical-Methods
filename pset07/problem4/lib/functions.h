#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <math.h>
#include <stdlib.h>
#include <string.h>

typedef double (*funcPtr) (double);

typedef struct {
    char* funcName;
    funcPtr func;
} FunctionMap;

funcPtr getFuncPtr(char *funcName);
funcPtr getd4FuncPtr(char *funcName);
double fx1(double x);
double d4fx1(double x);
double fx2(double x);

#endif
