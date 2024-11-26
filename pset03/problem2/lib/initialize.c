#include "initialize.h"

int size;

void def_size(int argc, char *argv) {
    if (argc < 2) {
        printf("Invalid number of arguments. \n");
        printf("Usage: ./multiply <matrix size n>\n");
        exit(EXIT_FAILURE);
    }
    size = atoi(argv);
    if (size < 2) {
        printf("Please input a valid matrix size.\n");
    }
}

double *allo_vec(int vec_size) {
    double *vec_name = malloc((vec_size + 1) * sizeof(double));
    if (vec_name == NULL) {
        perror("Error allocating vector memory!");
        exit(EXIT_FAILURE);
    }
    return vec_name;
}

// Allocating memory and assigning values to a vector
double *def_vec(int vec_size) {
    double *vec_name = allo_vec(vec_size);
    printf("=========================\n");
    printf("Define the vector values:\n");
    printf("=========================\n");

    for (int m = 0; m < size; m++) {
        double num = 0.0;
        printf("V_%i: ", m + 1);
        scanf("%lf", &num);
        vec_name[m] = num;
    }
    return vec_name;
}

// Allocating matrix memory
double *allo_mat(int mat_size) {
    double *mat_name = malloc(pow(mat_size + 1, 2) * sizeof(double));
    if (mat_name == NULL) {
        perror("Error allocating matrix memory!");
        exit(EXIT_FAILURE);
    }
    return mat_name;
}

// Assigning matrix values
double *def_mat(int mat_size) {
    double *mat_name = allo_mat(mat_size);
    printf("=========================\n");
    printf("Define the matrix values:\n");
    printf("=========================\n");

    for (int m = 0; m < mat_size; m++) {
        for (int n = 0; n < mat_size; n++) {
            double num = 0.0;
            int index = m * mat_size + n;
            printf("A_%i_%i: ", m + 1, n + 1);
            scanf("%lf", &num);
            mat_name[index] = num;
        }
        printf("\n");
    }
    return mat_name;
}
