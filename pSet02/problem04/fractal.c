#include <complex.h>
#include <math.h>
#include <stdio.h>

typedef struct {
    double complex root;
    double complex change;
    int count;
} Results;

double complex fz(double complex z);
double complex dfz(double complex z);
Results solve_cnewton(double complex z);

// The maximum number of loops to be executed (for testing)
const int nmax = 200;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-9;

// Defining the image height width (in pixels)
const int img_height = 4;
const int img_width = 4;

int main(void) {
    int xstart = -img_width >> 1;
    int xend = -xstart;
    int ystart = -img_height >> 1;
    int yend = -ystart;
    for (int x = xstart; x < xend; x++) {
        for (int y = ystart; y < yend; y++) {
            // Declaring the starting position for the algorithm
            double complex zstart = x + y * I;

            Results result = solve_cnewton(zstart);

            double complex z = result.root;
            double change = log10(result.change);
            double count = log10(result.count);
            double complex fofz = fz(z);

            // Printing the x, y, root, f(z), and log_10(iterations), and
            // log_10(error)
            printf(
                "x: %i, y: %i, z: %.12lf + %.12lfi, f(z): %.12lf + %.12lfi, "
                "log10(count): %lf, log10(error): %.12lf\n\n",
                x, y, creal(z), cimag(z), creal(fofz), cimag(fofz), count,
                change);
        }
    }
}
// Defining the given function
double complex fz(double complex z) { return cpow(z, 3) - 1; }

// Defining the derivative of the above function
double complex dfz(double complex z) { return 3 * cpow(z, 2); }

// Calculating the complex root of a function
Results solve_cnewton(double complex z1) {
    Results result;

    double complex z2 = z1;

    // Initializing the change with each loop and the loop counter;
    double change = 1;
    int count = 0;

    // Creating a loop that terminates when a and b are within an error, fz(c) =
    // 0, or the loop count is greater than the defined maximum
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
