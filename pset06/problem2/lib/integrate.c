#include "integrate.h"

// Declaring the given function
double fx(double x) {
    double value = 0;
    if (x == 0) {
        return value;
    }
    value = (pow(2.0, x) * sin(x)) / x;
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
    double integral = 0;

    // Creating an array of xValues at which to evaluate f(x)
    double xVals[4] = {-0.861136, -0.339981, 0.339981, 0.861136};
    double AVals[4] = {0.347855, 0.652145, 0.652145, 0.347855};

    // Calculating the approximation
    double subst1 = (params.xf - params.xi) / 2.0;
    double subst2 = (params.xf + params.xi) / 2.0;
    for (int i = 0; i < 4; i++) {
        integral += AVals[i] * fx(subst1 * xVals[i] + subst2);
    }
    integral *= subst1;

    return integral;
}
