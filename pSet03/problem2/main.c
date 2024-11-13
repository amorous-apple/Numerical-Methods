#include "lib/calc_system.h"
#include "lib/calc_test.h"
#include "lib/gauss.h"
#include "lib/initialize.h"

int main(int argc, char* argv[]) {
    // def_size(argc, argv[1]);
    int size = 3;

    // double* matrix = def_mat(size);
    // double* vector = def_vec(size);
    double matrix[] = {2.0, 0.1, -0.2, 0.05, 4.2, 0.032, 0.12, -0.07, 5.0};
    double vector[] = {10.0, 11.0, 12.0};

    printf("\n");
    printf("=========================\n");
    printf("Row Echelon Form: \n");
    printf("=========================\n");
    gaussinator(matrix, vector, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int index = i * size + j;
            printf("m_%d_%d: %lf, ", i + 1, j + 1, matrix[index]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i < size; i++) {
        printf("b_%d: %lf, ", i + 1, vector[i]);
    }

    printf("\n");
    printf("=========================\n");
    printf("Solution: \n");
    printf("=========================\n");
    double* sol = calc_system(matrix, vector, size);
    for (int i = 0; i < size; i++) {
        printf("R_%i: %lf\n", i + 1, sol[i]);
    }
    printf("\n");
    printf("=========================\n");
    printf("Error: \n");
    printf("=========================\n");
    printf("error = %.15lf", test_sol(matrix, sol, vector));

    // free(matrix);
    // free(vector);
}
