#include <math.h>
#include <stdio.h>

double fxy(double x, double y);
double gxy(double x, double y);
double dxfxy(double x, double y);
double dxgxy(double x, double y);
double dyfxy(double x, double y);
double dygxy(double x, double y);

double ix(double x);
double iy(double y);

// The maximum number of loops to be executed (for testing)
const int nmax = 15;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-6;

int main(void) {
    // Declaring the starting positions for the algorithm in four "cardinal
    // direction"
    double xstart[4] = {-1, 0, 1, 0};
    double ystart[4] = {0, 1, 0, -1};

    // Using a loop to check for all four root locations
    for (int i = 0; i < 4; i++) {
        double x1 = xstart[i];
        double y1 = ystart[i];

        double y2;
        double x2;

        // Initializing the change with each loop and the loop counter;
        double change = 1;
        int count = 0;

        // Creating a loop that terminates when x and y are within an error,
        // fxy(x,y) = gxy(x,y), or the loop count is greater than the defined
        // maximum
        while (!(fabs(change) < error || fxy(x1, y1) == gxy(x1, y1) ||
                 count >= nmax)) {
            count++;

            x2 = x1 -
                 ((fxy(x1, y1) * dygxy(x1, y1) - gxy(x1, y1) * dyfxy(x1, y1)) /
                  (dxfxy(x1, y1) * dygxy(x1, y1) -
                   dxgxy(x1, y1) * dyfxy(x1, y1)));
            y2 = y1 -
                 ((gxy(x1, y1) * dxfxy(x1, y1) - fxy(x1, y1) * dxgxy(x1, y1)) /
                  (dxfxy(x1, y1) * dygxy(x1, y1) -
                   dxgxy(x1, y1) * dyfxy(x1, y1)));

            change = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

            x1 = x2;
            y1 = y2;
        }

        // Printing the location of the root and how many iterations in took
        printf("This function has root %i at x = %.8lf, y = %.8lf\n", i + 1, x2,
               y2);
        printf(
            "Finding this root with an error of %.14lf took %i iterations.\n",
            fabs(change), count);
    }
    // Expanding the code to include an iterative approach for root finding.
    printf("==========================================\n");
    printf("Iterative Method \n");
    printf("==========================================\n");

    double xIter[4] = {2, -2, 1, -1};
    double yIter[4] = {1, -1, 2, -2};
    for (int i = 0; i < 4; i++) {
        // Initializing the change with each loop and the loop counter;
        double change = 1;
        int count = 0;

        double x1 = xIter[i];
        double y1 = yIter[i];

        double y2;
        double x2;

        while (!(fabs(change) < error || fxy(x1, y1) == gxy(x1, y1) ||
                 count >= nmax)) {
            count++;

            x2 = ix(x1);
            y2 = iy(y1);

            change = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

            x1 = x2;
            y1 = y2;
        }
        printf("This function has root %i at x = %.8lf, y = %.8lf\n", i + 1, x2,
               y2);
        printf(
            "Finding this root with an error of %.14lf took %i "
            "iterations.\n",
            fabs(change), count);
    }
}

// Defining the given functions
double fxy(double x, double y) { return x * y - 0.1; }
double gxy(double x, double y) { return x * x + 3 * y * y - 2; }

// Defining the derivatives of the above functions
double dxfxy(double x, double y) { return y; }
double dxgxy(double x, double y) { return 2 * x; }
double dyfxy(double x, double y) { return x; }
double dygxy(double x, double y) { return 6 * y; }

// Defining the iterative functions
double ix(double x) { return sqrt(2 - (0.03 / pow(x, 2))); }
double iy(double y) { return sqrt((2 - (0.01 / pow(y, 2))) / 3); }
