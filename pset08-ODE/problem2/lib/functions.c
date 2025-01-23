#include "functions.h"

// Defining the initial value of a function n (fi_n) and the function itself
// (f_n)

double fi_a(void) { return 1.0; }

double f_a(double x, double y) { return y * cos(x + y); }

double fi_b(void) { return 1.0; }

double f_b(double x, double y) { return sin(x * y) * cos(x + y); }

double fi_c(void) { return 1.0; }

double f_c(double x, double y) { return x * y - x * x; }

double fi_d(void) { return 1.0; }

double f_d(double x, double y) {
    (void)x;
    return y * (3.0 - y);
}

double fi_e(void) { return 1.0 / 2; }

double f_e(double x, double y) { return y * y - x * x; }

double fi_f(void) { return 0.0; }

double f_f(double x, double y) { return 1.0 / (3.0 * x - 2.0 * y + 1.0); }

double fi_test1(void) { return 1.0; }

double f_test1(double x, double y) {
    return -2.0 * y + pow(x, 3) * exp(-2.0 * x);
}
