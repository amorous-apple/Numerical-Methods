#include "fOfZ.h"

// Defining the given function
double complex fz(double complex z) { return cpow(z, 3) - 1; }

// Defining the derivative of the above function
double complex dfz(double complex z) { return 3 * cpow(z, 2); }
