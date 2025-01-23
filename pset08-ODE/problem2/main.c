#include <stdio.h>

#include "lib/functions.h"
#include "lib/init.h"
#include "lib/integrators.h"
#include "lib/utils_data.h"

int main(void) {
    double (*fnctPtr)(double, double) = f_f;
    double fnctI = fi_f();

    double **solution1 = RK4(fnctPtr, fnctI, X_MIN, X_MAX, NUM_STEPS);
    double **solution2 = Heun(fnctPtr, fnctI, X_MIN, X_MAX, NUM_STEPS);
    double **solution3 = Adams(fnctPtr, fnctI, X_MIN, X_MAX, NUM_STEPS);

    // for (int i = 0; i <= NUM_STEPS; i++) {
    //     printf("x: %.3lf, y: %.3lf\n", solution[i][0], solution[i][1]);
    // }

    data_write("f_f", solution1, solution2, solution3);
}
