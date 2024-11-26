#include "calc_eigen.h"

// Setting an acceptable error for calculating the eigenvalues
double error = 10e-6;
int max_count = 50;

double calc_eigen(double* mat, double* vec1, int sys_size) {
    double change = 1;
    int count = 0;

    // Initializing eigenvalue variables for calculating Aitken acceleration
    double eigenval1 = 0;
    double eigenval2 = 0;
    double eigenval3 = 0;
    double eigenvalAit = 0;
    double* vec2 = allo_vec(sys_size);

    while (change > error && count < max_count) {
        // Multiplying the current vector by the given matrix
        vec2 = calc_multiply(mat, vec1, sys_size);

        // Finding the eigenvalue by performing x^n+1 / x^n
        eigenval3 = vec2[0] / vec1[0];

        if (eigenval1 != 0) {
            eigenvalAit = (eigenval1 * eigenval3 - eigenval2 * eigenval2) /
                          (eigenval3 - 2 * eigenval2 + eigenval1);
        }

        change = fabs(eigenvalAit - eigenval3);

        // Storing the values from the previous two iterations for Aitken
        // acceleration
        eigenval1 = eigenval2;
        eigenval2 = eigenval3;
        eigenval3 = eigenvalAit;
        vec1 = vec2;

        vec_normalize(vec1, sys_size);

        count++;
    }
    printf("calc_eigen took %i iterations\n", count);
    for (int i = 0; i < sys_size; i++) {
        printf("u_%d: %.10lf\n", i + 1, vec1[i]);
    }

    free(vec2);
    return eigenvalAit;
}

// Normalizing the vector to help avoid divergence
void vec_normalize(double* vec, int sys_size) {
    double mag = 0.0;
    for (int i = 0; i < sys_size; i++) {
        mag += vec[i] * vec[i];
    }
    mag = sqrt(mag);

    for (int i = 0; i < sys_size; i++) {
        vec[i] /= mag;
    }
}
