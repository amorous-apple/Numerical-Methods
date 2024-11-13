#include "calc_system.h"

double* calc_system(double* mat, double* vec, int sys_size) {
    double* result = allo_vec(sys_size);
    // Iterating through the solution vector from bottom to top
    for (int i = sys_size - 1; i >= 0; i--) {
        // Calculating some usful indices
        int ind_diag = i * sys_size + i;

        // Initializing the vector component for the result
        double vec_comp = vec[i];

        // Iterating to subtract known values
        for (int j = i + 1; j < sys_size; j++) {
            int ind_mat = i * sys_size + j;
            vec_comp -= result[j] * mat[ind_mat];
        }

        if (mat[ind_diag] == 0) {
            printf("Diagonal element M_%d_%d cannot be zero!", i + 1, i + 1);
            exit(EXIT_FAILURE);
        }
        vec_comp = vec_comp / mat[ind_diag];
        result[i] = vec_comp;
    }
    return result;
}

// Some pseudocode to understand that construction of the program
// R = Result, V = Vector, M = Matrix
// R_n = V_n / M_n_n
// R_n-1 = [ V_n-1 - (R_n * M_n-1_n) ] / M_n-1_n-1
// R_n-2 = [ V_n-1 - (R_n * M_n-2_n) - (R_n-1 * M_n-2_n-1) ] / M_n-2_n-2
