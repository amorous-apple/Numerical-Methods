#include "integrators.h"

// Calculating the integral of a function using the trapezoidal rule
double int_trap(Integral *I) {
    double integralVal = 0.0;
    for (int i = 0; i < I->numPoints - 1; i++) {
        double h = I->dataX[i + 1] - I->dataX[i];
        integralVal += (I->dataY[i + 1] + I->dataY[i]) * h;
    }
    integralVal *= 1.0 / 2;

    return integralVal;
}

// Calculating the integral of a function using Simpson's 3/8 Rule
double int_simp38(Integral *I) {
    double integralVal = 0.0;

    // Calculating how many intervals Simpson's 3/8 Rule can be used on
    int numSubIntervals = (I->numPoints - 1) / 3;
    // Calculating how many points are 'left over' to be integrated by other
    // means
    int numLeftover = (I->numPoints - 1) % 3;

    double iterationSum;
    for (int i = 0; i < numSubIntervals; i++) {
        iterationSum = I->dataY[i * 3] + 3.0 * I->dataY[i * 3 + 1] +
                       3.0 * I->dataY[i * 3 + 2] + I->dataY[i * 3 + 3];
        integralVal += iterationSum;
    }
    // Prefactor
    double h = I->dataX[1] - I->dataX[0];
    integralVal *= h * 3.0 / 8;

    // Integrating the remaining 1 or 2 points using the trapezoidal rule
    if (numLeftover > 0) {
        Integral Leftover;

        Leftover.numPoints = numLeftover + 1;
        Leftover.fnctPtr = I->fnctPtr;
        Leftover.ptA = I->dataX[numSubIntervals * 3];
        Leftover.ptB = I->ptB;
        Leftover.dataX = &I->dataX[numSubIntervals * 3];
        Leftover.dataY = &I->dataY[numSubIntervals * 3];

        integralVal += int_trap(&Leftover);
    }

    return integralVal;
}

// Calculating the error given a numerical integral value
// ('true' values calcualted using Mathematica)
double calc_error(double integralVal) {
    double trueVal;
    switch (FUNC_ID) {
        case 1:
            trueVal = 1.905238690482676;
            break;
        case 2:
            trueVal = 19.71765748201623;
            break;
        case 3:
            trueVal = 3.249390388765902;
            break;
    }

    return fabs(trueVal - integralVal);
}
