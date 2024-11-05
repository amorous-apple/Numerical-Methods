#include "solve_cnewton.h"

// Calculating the complex root of a function
Results solve_cnewton(double complex z1) {
    Results result;

    // Initializing the change with each loop and the loop counter;
    double change = 1;
    int count = 0;

    // Creating a loop that terminates when a and b are within an error, fz(c) =
    // 0, or the loop count is greater than the defined maximum
    if (dfz(z1) == 0) {
        result.root = 0.0 + 0.0 * I;
        result.change = 0;
        result.count = count;
        return result;
    }

    double complex z2 = z1;
    while (!(change < error || fz(z2) == 0 || count >= nmax)) {
        count++;
        z1 = z2;
        z2 = z1 - fz(z1) / dfz(z1);
        change = cabs(z2 - z1);
    }
    result.root = z2;
    result.change = change;
    result.count = count;
    return result;
}
