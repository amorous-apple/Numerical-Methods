#include "integrators.h"

// Using RK4 to calculate numSteps pairs of (x, y) for a DE given a function
// pointer and an initial value y_0
double **RK4(double (*fnctPtr)(double, double), double yInitial, double xStart,
             double xEnd, int numSteps) {
    double **result = malloc((numSteps + 1) * sizeof(double *));
    double *doubleArr = malloc(2 * (numSteps + 1) * sizeof(double));
    if (result == NULL || doubleArr == NULL) {
        perror("Error allocating memory for result or doubleArr\n");
    }
    for (int i = 0; i < numSteps + 1; i++) {
        result[i] = doubleArr + i * 2;
    }
    result[0][0] = xStart;
    result[0][1] = yInitial;

    double h = (xEnd - xStart) / numSteps;
    double xVal;
    double yVal;

    double k1, k2, k3, k4;

    for (int i = 1; i <= numSteps; i++) {
        xVal = xStart + i * h;
        yVal = result[i - 1][1];

        k1 = h * fnctPtr(xVal, yVal);
        k2 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k1);
        k3 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k2);
        k4 = h * fnctPtr(xVal + h, yVal + k3);

        result[i][0] = xVal;
        result[i][1] = yVal + (1.0 / 6) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
    }

    return result;
}

// Using Heun's method to calculate numSteps pairs of (x, y) for a DE given a
// function pointer and an initial value y_0
double **Heun(double (*fnctPtr)(double, double), double yInitial, double xStart,
              double xEnd, int numSteps) {
    double **result = malloc((numSteps + 1) * sizeof(double *));
    double *doubleArr = malloc(2 * (numSteps + 1) * sizeof(double));
    if (result == NULL || doubleArr == NULL) {
        perror("Error allocating memory for result or doubleArr\n");
    }
    for (int i = 0; i < numSteps + 1; i++) {
        result[i] = doubleArr + i * 2;
    }
    result[0][0] = xStart;
    result[0][1] = yInitial;

    double h = (xEnd - xStart) / numSteps;
    double xVal;
    double yValIntermediate, yVal;

    for (int i = 1; i <= numSteps; i++) {
        xVal = xStart + i * h;
        yVal = result[i - 1][1];
        yValIntermediate = yVal + h * fnctPtr(xVal, yVal);

        result[i][0] = xVal;
        result[i][1] = yVal + (h / 2) * (fnctPtr(xVal, yVal) +
                                         fnctPtr(xVal + h, yValIntermediate));
    }

    return result;
}

// Using Adams' method to calculate numSteps pairs of (x, y) for a DE given a
// function pointer and an initial value y_0
double **Adams(double (*fnctPtr)(double, double), double yInitial,
               double xStart, double xEnd, int numSteps) {
    double **result = malloc((numSteps + 1) * sizeof(double *));
    double *doubleArr = malloc(2 * (numSteps + 1) * sizeof(double));
    if (result == NULL || doubleArr == NULL) {
        perror("Error allocating memory for result or doubleArr\n");
    }
    for (int i = 0; i < numSteps + 1; i++) {
        result[i] = doubleArr + i * 2;
    }
    result[0][0] = xStart;
    result[0][1] = yInitial;

    double h = (xEnd - xStart) / numSteps;
    double xVal, xValPrev;
    double yVal, yValPrev;
    double k1, k2, k3, k4;

    // Calculating the first step using RK4
    xVal = xStart + h;
    yVal = result[0][1];
    k1 = h * fnctPtr(xVal, yVal);
    k2 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k1);
    k3 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k2);
    k4 = h * fnctPtr(xVal + h, yVal + k3);

    result[1][0] = xVal;
    result[1][1] = yVal + (1.0 / 6) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);

    for (int i = 2; i <= numSteps; i++) {
        xVal = xStart + i * h;
        xValPrev = xVal - h;
        yVal = result[i - 1][1];
        yValPrev = result[i - 2][1];

        result[i][0] = xVal;
        result[i][1] = yVal + (h / 2) * (fnctPtr(xValPrev, yValPrev) +
                                         fnctPtr(xVal, yVal));
    }

    return result;
}

// Using the Adams-Moulton method to calculate numSteps pairs of (x, y) for a DE
// given a function pointer and an initial value y_0
double **AdamsMoulton(double (*fnctPtr)(double, double), double yInitial,
                      double xStart, double xEnd, int numSteps) {
    double **result = malloc((numSteps + 1) * sizeof(double *));
    double *doubleArr = malloc(2 * (numSteps + 1) * sizeof(double));
    if (result == NULL || doubleArr == NULL) {
        perror("Error allocating memory for result or doubleArr\n");
    }
    for (int i = 0; i < numSteps + 1; i++) {
        result[i] = doubleArr + i * 2;
    }
    result[0][0] = xStart;
    result[0][1] = yInitial;

    double h = (xEnd - xStart) / numSteps;
    double xVal, xValPrev;
    double yVal, yValPrev;
    double k1, k2, k3, k4;

    // Calculating the first few steps using RK4
    int numPreSteps = 4;
    for (int i = 1; i <= numPreSteps; i++) {
        xVal = xStart + i * h;
        yVal = result[i - 1][1];

        k1 = h * fnctPtr(xVal, yVal);
        k2 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k1);
        k3 = h * fnctPtr(xVal + (1.0 / 2) * h, yVal + (1.0 / 2) * k2);
        k4 = h * fnctPtr(xVal + h, yVal + k3);

        result[i][0] = xVal;
        result[i][1] = yVal + (1.0 / 6) * (k1 + 2.0 * k2 + 2.0 * k3 + k4);
    }

    // Calculating the remaining steps with Adams-Moulton
    for (int i = numPreSteps + 1; i <= numSteps; i++) {
        xVal = xStart + i * h;
        xValPrev = xVal - h;
        yVal = result[i - 1][1];
        yValPrev = result[i - 2][1];

        result[i][0] = xVal;
        result[i][1] = yVal + (h / 2) * (fnctPtr(xValPrev, yValPrev) +
                                         fnctPtr(xVal, yVal));
    }

    return result;
}
