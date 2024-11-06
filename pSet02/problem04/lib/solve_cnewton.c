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

    // Preventing diverging answers for non-convergence
    if (count == nmax) {
        result.root = 0;
        result.change = 1;
        result.count = count;
        return result;
    } else {
        result.root = z2;
        result.change = change;
        result.count = count;
        return result;
    }
}

Datavals def_data(double complex zstart) {
    Results result = solve_cnewton(zstart);

    Datavals data;
    data.realZ = creal(result.root);
    data.imagZ = cimag(result.root);

    double complex fofz = fz(result.root);
    data.realFofz = creal(fofz);
    data.imagFofz = cimag(fofz);

    double count;
    if (result.count == 0) {
        count = 0;
    } else {
        count = log10(result.count);
    }
    data.count = count;

    return data;
}
