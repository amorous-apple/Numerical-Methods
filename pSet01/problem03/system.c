#include <math.h>
#include <stdio.h>

double fx(double x, double y);
double gx(double x, double y);
double dxfx(double x, double y);
double dxgx(double x, double y);
double dyfx(double x, double y);
double dygx(double x, double y);

// The maximum number of loops to be executed (for testing)
const int nmax = 1000;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-17;

int main(void) {
    // Declaring the starting positions for the algorithm
    double x1 = 1.0;
    double x2 = 0;
    double y1 = 1.0;
    double y2 = 0;

    // Initializing the change with each loop and the loop counter;
    double change = 1;
    int count = 0;

    // Creating a loop that terminates when a and b are within an error, fx(c) =
    // 0, or the loop count is greater than the defined maximum
    while (
        !(fabs(change) < error || fx(x1, y1) == gx(x1, y1) || count >= nmax)) {
        count++;
        change = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        x2 = x1 - ((fx(x1, y1) * dygx(x1, y1) - gx(x1, y1) * dyfx(x1, y1)) /
                   (dxfx(x1, y1) * dygx(x1, y1) - dxgx(x1, y1) * dyfx(x1, y1)));
        y2 = y1 - ((gx(x1, y1) * dxfx(x1, y1) - fx(x1, y1) * dxgx(x1, y1)) /
                   (dxfx(x1, y1) * dygx(x1, y1) - dxgx(x1, y1) * dyfx(x1, y1)));
    }

    // Printing the location of the root and how many iterations in took
    printf("This function has a root at x = %.8lf, y = %.8lf\n", x2, y2);
    printf("Finding this root with an error of %.20lf took %i iterations.\n",
           fabs(change), count);
}

// Defining the given functions
double fx(double x, double y) { return x * y - 0.1; }
double gx(double x, double y) { return x * x + 3 * y * y - 2; }

// Defining the derivatives of the above functions
double dxfx(double x, double y) { return y; }
double dxgx(double x, double y) { return 2 * x; }
double dyfx(double x, double y) { return x; }
double dygx(double x, double y) { return 6 * y; }
