#include <math.h>
#include <stdio.h>

double fx(double x);
double dfx(double x);

// The maximum number of loops to be executed (for testing)
const int nmax = 1000;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-6;

int main(void) {
    // Declaring the starting position for the algorithm
    double a = 5.0;
    double b = a - 1;

    // Initializing the change with each loop and the loop counter;
    double change = 1;
    int count = 0;

    // Creating a loop that terminates when a and b are within an error, fx(c) =
    // 0, or the loop count is greater than the defined maximum
    while (!(fabs(change) < error || fx(b) == 0 || count >= nmax)) {
        count++;
        change = b - a;
        b = a;
        a = a - fx(a) / dfx(a);
    }

    // Printing the location of the root and how many iterations in took
    printf("This function has a root at x = %.20lf\n", b);
    printf("Finding this root with an error of %.20lf took %i iterations.\n",
           fabs(change), count);
}

// Defining the given function
double fx(double x) { return x * cos(x) - sin(x); }

// Defining the derivative of the above function
double dfx(double x) { return -x * sin(x); }

