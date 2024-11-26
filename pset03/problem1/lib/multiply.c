#include "multiply.h"

// NOTE: This function was tested with the vector and matrix given in the
// assignment and the answer was checked against an online calculator.
double* calc_multiply(double* matrix, double* vector, int result_size) {
    double* result = allo_vec(result_size);
    // Calculating each value for the result vector
    for (int m = 0; m < size; m++) {
        double component_total = 0;

        for (int n = 0; n < size; n++) {
            int index_matrix = m * size + n;
            component_total += vector[n] * matrix[index_matrix];
        }
        result[m] = component_total;
    }
    // // Printing the result of the vector multiplication to the console
    // printf("\n");
    // printf("=========================\n");
    // printf("Answer: \n");
    // printf("=========================\n");
    // for (int m = 0; m < size; m++) {
    //     printf("R_%i: %lf", m + 1, result[m]);
    //     if (m < size - 1) {
    //         printf(", ");
    //     }
    // }
    return result;
}
