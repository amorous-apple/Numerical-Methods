#include <stdio.h>

#include "lib/functions.h"
#include "lib/init.h"
#include "lib/integrate.h"

int main(int argc, char **argv) {
    init(argc, argv);
    printf("method: %s, function: %s, a: %lf, b: %lf, numPoints: %d\n",
           params.method, params.function, params.a, params.b,
           params.numPoints);
    putchar('\n');

    double *funcArr = fillArr(getFuncPtr(params.function), params.a, params.b,
                              params.numPoints);
    printf("funcArr:\n\t");
    for (int i = 0; i < params.numPoints; i++) {
        printf("%lf, ", funcArr[i]);
    }
    putchar('\n');

    double error[1] = {-1.0};
    double integral = chooseInt(params.method, funcArr, params.a, params.b,
                                params.numPoints, error);
    // double integral =
    //     calcInt_newton(funcArr, params.a, params.b, params.numPoints, error);
    printf("Integral: %lf\n", integral);
    printf("Error: %lf\n", error[0]);
}
