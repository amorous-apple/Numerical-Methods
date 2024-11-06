#include "fOfZ.h"

// // Defining the first function and its derivative
// double complex fz(double complex z) { return cpow(z, 3) - 1; }
// double complex dfz(double complex z) { return 3 * cpow(z, 2); }

// Defining the second function and its derivative
double complex fz(double complex z) {
    return 35 * cpow(z, 9) - 180 * cpow(z, 7) + 378 * cpow(z, 5) -
           420 * cpow(z, 3) + 315 * z;
}
double complex dfz(double complex z) {
    return 315 * cpow(z, 8) - 1260 * cpow(z, 6) + 1890 * cpow(z, 4) -
           1260 * cpow(z, 2) + 315;
}

// // Defining a test function and its derivative
// double complex fz(double complex z) {
//     return 35 * cpow(z, 9) - 180 * cpow(z, 7) + 378 * cpow(z, 5) -
//            420 * cpow(z, 3);
// }
// double complex dfz(double complex z) {
//     return 315 * cpow(z, 8) - 1260 * cpow(z, 6) + 1890 * cpow(z, 4) -
//            1260 * cpow(z, 2);
// }
