#include "functions.h"

double func1(double input) { return exp(input) * cos(input); }

double func2(double input) { return exp(input); }

double func3(double input) {
    if (input < 0) {
        return exp(2.0 * input);
    } else {
        return input - 2.0 * cos(input) + 4;
    }
}
