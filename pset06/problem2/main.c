#include <stdio.h>

#include "lib/init.h"
#include "lib/integrate.h"

int main(int argc, char **argv) {
    init(argc, argv);
    printf("\tmethod: %c, xi: %lf, xf: %lf\n\n", params.method, params.xi,
           params.xf);
    double integral = integrate();
    printf("\tIntegral values: %lf\n", integral);

    double trueVal = 1.41891918440222;
    double percentDiff = ((integral - trueVal) / trueVal) * 100;
    printf(
        "This differs fromt the 'true value' from Mathematica by: %.10lf %%\n",
        percentDiff);
}
