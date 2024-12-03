#include "integrate.h"

// Declaring the given function
double fxy(double x, double y) {
    double value = x * y * y;
    return value;
}

// Selecting the method of integration and carrying it out
double integrate() {
    double integral;
    switch (params.equation) {
        case 1:
            integral = integ1(params.a, params.b, params.c, params.d);
            break;
        case 2:
            integral = integ2();
            break;
        case 3:
            integral = integ3();
            break;
    }
    return integral;
}

double integ1(double a, double b, double c, double d) {
    double integral;

    double hx = (d - c) / 2.0;
    double hy = (b - a) / 2.0;

    double xv[3] = {c, c + hx, d};
    double yv[3] = {a, a + hy, b};

    double pre = ((d - c) * (b - a)) / 36.0;
    double y0 = fxy(xv[0], yv[0]) + 4 * fxy(xv[1], yv[0]) + fxy(xv[2], yv[0]);
    double y1 = fxy(xv[0], yv[1]) + 4 * fxy(xv[1], yv[1]) + fxy(xv[2], yv[1]);
    double y2 = fxy(xv[0], yv[2]) + 4 * fxy(xv[1], yv[2]) + fxy(xv[2], yv[2]);

    integral = y0 + 4 * y1 + y2;
    integral *= pre;

    return integral;
}

double integ2() {
    double integral = 0;
    return integral;
}

double integ3() {
    double integral = 0;
    return integral;
}
