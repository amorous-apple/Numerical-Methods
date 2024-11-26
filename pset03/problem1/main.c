#include "lib/calc_system.h"
#include "lib/calc_test.h"
#include "lib/initialize.h"

int main(int argc, char* argv[]) {
    def_size(argc, argv[1]);

    double* matrix = def_mat(size);
    double* vector = def_vec(size);

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
    printf("error = %.20lf", test_sol(matrix, sol, vector));

    free(matrix);
    free(vector);
}
