#include <math.h>
#include <stdio.h>

double fx(double x);
double dfx(double x);

// The maximum number of loops to be executed (for testing)
const int nmax = 1000;

// Defining an acceptable error at which to stop the root search
const double error = 1.0e-17;

int main(void) {
    // Declaring the starting position for the algorithm
    double a = 1.0;
    double b = 0;

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
double fx(double x) {
    return exp(sqrt(5) * x) - 13.5 * cos(0.1 * x) + 25 * pow(x, 4);
}

// Defining the derivative of the above function
double dfx(double x) {
    return sqrt(5) * exp(sqrt(5 * x)) + 13.5 * 0.1 * sin(0.1 * x) +
           100 * pow(x, 3);
}
