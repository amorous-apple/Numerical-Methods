#include <stdio.h>

#include "lib/diff.h"
#include "lib/init.h"
#include "lib/integrate.h"

int main(int argc, char **argv) {
    init(argc, argv);
    printf("\tEquation ID: %d\n", params.equation);
    printf("\tTrue Value: %.10lf\n", params.trueVal);

    double integral = integrate();
    printf("\tIntegral value: %lf\n", integral);

    if (params.equation == 3) {
        printf("No comparison values given.\n");
        exit(EXIT_SUCCESS);
    } else {
        double percentDiff = calcDiff(integral);
        printf(
            "This differs from the 'true value' given on the problem set by: "
            "%.10lf %%\n",
            percentDiff);
    }
}
