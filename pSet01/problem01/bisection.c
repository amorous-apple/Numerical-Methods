#include <math.h>
#include <stdio.h>

double fx(double x);

// The maximum number of loops to be executed (for testing)
const int nmax = 1000;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-17;

int main(void) {
    // Declaring the starting positions a and b for the bisection algorithm
    double a = 0.0;
    double b = 1.0;

    // Terminate the program if the function has the same sign at both starting
    // points
    if (fx(a) * fx(b) >= 0) {
        printf("Bad starting points.\n");
        return 1;
    }

    // Initializing c and the loop counter;
    double c = a;
    double change = b - a;
    int count = 0;

    // Creating a loop that terminates when a and b are within an error, fx(c) =
    // 0, or the loop count is greater than the defined maximum
    while (!(fabs(change) < error || fx(c) == 0 || count >= nmax)) {
        count++;
        c = (a + b) / 2;
        if (fx(c) * fx(a) < 0) {
            change = c - b;
            b = c;
            // printf("b set to: %.8lf\n", c);
        } else {
            change = c - a;
            a = c;
            // printf("a set to: %.8lf\n", c);
        }
    }

    // Printing the location of the root and how many iterations in took
    printf("This function has a root at x = %.20lf\n", c);
    printf("Finding this root with an error of %.20lf took %i iterations.\n",
           fabs(change), count);
}

// Defining the given function
double fx(double x) {
    return exp(sqrt(5) * x) - 13.5 * cos(0.1 * x) + 25 * pow(x, 4);
}
