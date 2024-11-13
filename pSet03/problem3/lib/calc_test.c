#include "calc_test.h"

// Calculating the total error between M * x - b to check the accuracy of a
// solution
double test_sol(double* mat, double* vec_x, double* vec_b) {
    double* vec_b2 = calc_multiply(mat, vec_x, size);
    double error_total = 0;
    for (int i = 0; i < size; i++) {
        error_total += fabs(vec_b2[i] - vec_b[i]);
    }
    return error_total;
}
