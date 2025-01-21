#include "integrate.h"

// Fills an array with values along the interval of integration using the input
// function
double *fillArr(funcPtr func, double a, double b, int numPoints) {
    double *funcArr = malloc(numPoints * sizeof(double));
    if (funcArr == NULL) {
        perror("Error allocating memory for funcArr\n");
        exit(EXIT_FAILURE);
    }

    double h = (b - a) / (numPoints - 1);
    for (int i = 0; i < numPoints; i++) {
        funcArr[i] = func(a + i * h);
    }
    return funcArr;
}

// Implementing Newton-Cotes integration
double calcInt_newton(double *funcArr, double a, double b, int numPoints,
                      double *error) {
    if (numPoints % 2 == 0) {
        printf("Please enter an odd number of points!\n");
        exit(EXIT_FAILURE);
    }

    double h = (b - a) / (numPoints - 1);
    // Calculating the Integral based on the the structure of the composite
    // Simpson's 1/3 Rule
    double Integral = funcArr[0] + funcArr[numPoints - 1];
    for (int i = 1; i < numPoints - 1; i++) {
        Integral += (i % 2 == 0 ? 2 : 4) * funcArr[i];
    }
    Integral *= h / 3;

    error[0] = ((double)1 / 90) * pow(h, 4) * getd4FuncPtr(params.function)(a);

    return Integral;
}

// Creating a lookup table for the integration methods
MethodMap methodTable[] = {{"newton", &calcInt_newton}, {NULL, NULL}};

// Retrieving the integration function pointers from their names
methodPtr getMethodPtr(char *methodName) {
    for (int i = 0; methodTable[i].methodName != NULL; i++) {
        if (strcmp(methodName, methodTable[i].methodName) == 0) {
            return methodTable[i].method;
        }
    }
    printf("Invalid method!\n");
    return NULL;
}

// Choosing and executing the integration
double chooseInt(char *methodName, double *funcArr, double a, double b,
                 int numPoints, double *error) {
    return getMethodPtr(methodName)(funcArr, a, b, numPoints, error);
}
