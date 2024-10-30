#include <complex.h>
#include <math.h>
#include <omp.h>
#include <stdio.h>

typedef struct {
    double complex root;
    double complex change;
    int count;
} Results;

double complex fz(double complex z);
double complex dfz(double complex z);
Results solve_cnewton(double complex z);

// The maximum number of loops to be executed
const int nmax = 200;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-9;

// Defining the image width and height (in pixels)
const int img_width = 4000;
const int img_height = 4000;

// Defining the plotting range by choosing two points to define a rectangle
// (pick the bottom left and top right points as p1 and p2 respectively)
const double p1_x = -2;
const double p1_y = -2;
const double p2_x = 2;
const double p2_y = 2;

int main(void) {
    // Opening a file to write the calculated data
    FILE *file = fopen("fractal_data.csv", "a");
    if (file == NULL) {
        printf("File not found!\n");
        return 1;
    }

    // Calculating the step size for the loop
    double xstep = fabs(p2_x - p1_x) / img_width;
    double ystep = fabs(p2_y - p1_y) / img_height;

    // Defining the starting points for the loops
    double xstart = p1_x;
    double xend = p2_x;
    double ystart = p1_y;
    double yend = p2_y;

    // Iterating through every pixel in the image using x and y coordinates to
    // represent real and imaginary numbers in the complex plane.
    for (double x = xstart; x <= xend; x += xstep) {
#pragma omp parallel for
        for (int j = 0; j < img_height; j++) {
            double y = ystart + j * ystep;

            // Declaring the starting position for the algorithm
            double complex zstart = x + y * I;

            Results result = solve_cnewton(zstart);

            double complex z = result.root;
            double change = log10(result.change);
            double count = log10(result.count);
            double complex fofz = fz(z);

            // Printing the x, y, root, f(z), and log_10(iterations), and
            // log_10(error)
            // printf(
            //     "x: %f, y: %f, k(z): %.12lf + %.12lfi, f(z): %.12lf +
            //     %.12lfi, " "log10(count): %.2lf, log10(error): %.2lf\n", x,
            //     y, creal(z), cimag(z), creal(fofz), cimag(fofz), count,
            //     change);

            fprintf(file, "%.15lf %.15lf %.15lf\n", x, y, cimag(z));
        }
        // Printing a new line every time x changes to correct formatting for
        // gnuplot
        fprintf(file, "\n");
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
    // (count begins at 1 to avoid -inf when calculating log10(count))
    int count = 1;

    // Creating a loop that terminates when a and b are within an error, fz(c) =
    // 0, or the loop count is greater than the defined maximum
    if (dfz(z1) == 0) {
        result.root = 0.0 + 0.0 * I;
        result.change = change;
        result.count = count;
        return result;
    }
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
