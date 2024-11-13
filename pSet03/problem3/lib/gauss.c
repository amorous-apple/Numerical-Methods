#include "gauss.h"

void gaussinator(double* mat, double* vecb, int sys_size) {
    for (int i = 0; i < sys_size; i++) {
        int ind_diag = i * sys_size + i;
        if (mat[ind_diag] == 0) {
            perror("Diagonal matrix elements cannot be zero!\n");
            exit(EXIT_FAILURE);
        }
        double temp_diag = mat[ind_diag];

        // Dividing row i by the diagonal element m_i_i
        for (int j = 0; j < sys_size; j++) {
            int ind_mat = i * sys_size + j;
            mat[ind_mat] = mat[ind_mat] / temp_diag;
            // printf("mat[%d,%d] = mat[%d, %d] / mat[%d, %d]\n", i, j, i, j, i,
            //        i);
        }

        // Dividing vecb[i] by the diagonal element m_i_i
        vecb[i] = vecb[i] / temp_diag;
        // printf("vecb[%d] = %lf / %lf\n", i + 1, vecb[i], temp_diag);

        // Substracting (row i) * m_j_i from row j
        // Subtracting vecb[i] * m_j_i from vecb[j]
        for (int j = i + 1; j < sys_size; j++) {
            // Index of the element m_j_i to multiply
            int ind_mat_ji = j * sys_size + i;
            double temp_mat_ji = mat[ind_mat_ji];

            for (int k = 0; k < sys_size; k++) {
                // Index of the element to be modified
                int ind_mat_jk = j * sys_size + k;
                // Index of the element m_i_k for an element of the row being
                // subtracted
                int ind_mat_ik = i * sys_size + k;

                mat[ind_mat_jk] -= mat[ind_mat_ik] * temp_mat_ji;
            }
            vecb[j] -= vecb[i] * temp_mat_ji;
        }
    }
}
