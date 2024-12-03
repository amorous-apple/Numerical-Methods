#include "init.h"

Parameters params;
void init(int argc, char **argv) {
    if (argc == 1) {
        printf("Default parameters used. \n");
        printf(
            "Please provide command line arguments for different results. "
            "\n\n");
        params.method = 'r';
        params.xi = 0.1;
        params.xf = 1.1;
    } else if (argc != 4) {
        printf("Improper number of command line arguments!\n");
        printf("Usage: ./integratorinator <method> <x_i> <x_f>\n");
        printf("Valid methods include: \n");
        printf("    's' - Simpson's 1/3 rule\n");
        printf("    'r' - Romberg with Simpson's 1/3rule\n");
        printf("    'g' - Gauss-Legendre with 4 points\n");
        exit(EXIT_FAILURE);
    } else {
        char method = argv[1][0];
        if (!(method == 's' || method == 'r' || method == 'g')) {
            printf("Invalid integrator option!\n");
            printf("Run ./integratorinator h to see usage\n");
            exit(EXIT_FAILURE);
        }
        params.method = argv[1][0];
        params.xi = strtod(argv[2], NULL);
        params.xf = strtod(argv[3], NULL);
        if (params.xi > params.xf) {
            printf("xi should be smaller than xf!\n");
            exit(EXIT_FAILURE);
        }
    }
}
