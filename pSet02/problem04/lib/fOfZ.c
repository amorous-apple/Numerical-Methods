#include "fOfZ.h"

// // Defining the first function and its derivative
// double complex fz(double complex z) { return cpow(z, 3) - 1; }
// double complex dfz(double complex z) { return 3 * cpow(z, 2); }

// // Defining the second function and its derivative
// double complex fz(double complex z) {
//     return 35 * cpow(z, 9) - 180 * cpow(z, 7) + 378 * cpow(z, 5) -
//            420 * cpow(z, 3) + 315 * z;
// }
// double complex dfz(double complex z) {
//     return 315 * cpow(z, 8) - 1260 * cpow(z, 6) + 1890 * cpow(z, 4) -
//            1260 * cpow(z, 2) + 315;
// }

// Defining functions that can be used to mimick a Julia set
// cpow((z - a), (1 / (b - a))) * cpow((z - b), (1 / (a - b)))

// const double complex a = 0.9994 - 0.5286 * I;
// const double complex b = 0.0006 + 0.5286 * I;
const double complex a = 1.4623 - 0.1413 * I;
const double complex b = -0.4623 + 0.1413 * I;

const double complex b1 = 1 / (b - a);
const double complex b2 = 1 / (a - b);
double complex fz(double complex z) {
    double complex temp = b1 / (z - a) + b2 / (z - b);
    return 1 / temp;
}
double complex dfz(double complex z) { return 1; }
