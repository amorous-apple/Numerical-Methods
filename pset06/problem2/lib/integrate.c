#include "integrate.h"

// Declaring the given function
double fx(double x) {
    double value = (pow(2.0, x) * sin(x)) / x;
    return value;
}

// Selecting the method of integration and carrying it out
double integrate() {
    double integral;
    switch (params.method) {
        case 's':
            integral = simpson();
            break;
        case 'r':
            integral = rhomberg();
            break;
        case 'g':
            integral = gauss();
            break;
    }
    return integral;
}

// Calculating Simpson's 1/3 rule
double simpson() {
    double integral;

    // Calculating the step size
    double intervals = (float)2;
    double stepSize = (params.xf - params.xi) / intervals;

    // Creating an array of xValues at which to evaluate f(x)
    int numOfVals = (int)intervals + 1;
    double xVals[numOfVals];
    for (int i = 0; i < numOfVals; i++) {
        xVals[i] = params.xi + i * stepSize;
    }

    // Calculating the approximation
    integral =
        (stepSize / 3) * (fx(xVals[0]) + 4 * fx(xVals[1]) + fx(xVals[2]));
    return integral;
}

// Calculating Simpson's 1/3 rule combined with Rhomberg integration
double rhomberg() {
    double integral;

    // Calculating the step size
    double intervals = (float)4;
    double stepSize = (params.xf - params.xi) / intervals;

    // Creating an array of xValues at which to evaluate f(x)
    int numOfVals = (int)intervals + 1;
    double xVals[numOfVals];
    for (int i = 0; i < numOfVals; i++) {
        xVals[i] = params.xi + i * stepSize;
    }

    // Calculating the approximation
    integral = (2 * stepSize / 45) *
               (7 * fx(xVals[0]) + 32 * fx(xVals[1]) + 12 * fx(xVals[2]) +
                32 * fx(xVals[3]) + 7 * fx(xVals[4]));
    return integral;
}

// Calculating the integral using Gauss-Legendre with 4 points
double gauss() {
    double integral;

    // Calculating the step size
    double intervals = (float)4;
    double stepSize = (params.xf - params.xi) / intervals;

    // Creating an array of xValues at which to evaluate f(x)
    int numOfVals = (int)intervals + 1;
    double xVals[numOfVals];
    for (int i = 0; i < numOfVals; i++) {
        xVals[i] = params.xi + i * stepSize;
    }

    // Calculating the approximation
    integral = (2 * stepSize / 45) *
               (7 * fx(xVals[0]) + 32 * fx(xVals[1]) + 12 * fx(xVals[2]) +
                32 * fx(xVals[3]) + 7 * fx(xVals[4]));
    return integral;
}
