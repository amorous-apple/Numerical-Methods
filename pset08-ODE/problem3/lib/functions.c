#include "functions.h"

// Defining the initial value of a function n (fi_n) and the function itself
// (f_n)
double fi_a() { return 0.1; }
double f_a(double x, double y) { return y + x * x - 2.0 * x + sin(x); }

double fi_b() { return 2.0; }
double f_b(double x, double y) { return 0; }
