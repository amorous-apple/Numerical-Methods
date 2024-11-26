#include "lib/calc_eigen.h"

int main(void) {
    int size = 3;

    double matrix[] = {6, 5, -5, 2, 6, -2, 2, 5, -1};
    double vector[] = {3, 4, 5};

    printf("\n");
    printf("=========================\n");
    printf("Eigenvalue: \n");
    printf("=========================\n");
    double eigenval = calc_eigen(matrix, vector, size);
    printf("e(main): %.10lf\n", eigenval);
    // for (int i = 0; i < size; i++) {
    //     printf("u_%d: %lf\n", i + 1, vector[i]);
    // }
}
