#include "init.h"

Parameters params;
void init(int argc, char **argv) {
    if (argc != 2) {
        printf("Invalid number of command line arguments!\n");
        printf("Usage: \n");
        printf("\t./integratinator2D <equation num>\n");
        printf("\tValid options include: 1, 2, 3\n");
        exit(EXIT_FAILURE);
    } else {
        params.equation = atoi(argv[1]);
        if (!(params.equation == 1 || params.equation == 2 ||
              params.equation == 3)) {
            printf("Invalid equation number!\n");
            exit(EXIT_FAILURE);
        }
        switch (params.equation) {
            case 1:
                params.trueVal = 2.0 / 3.0;
                break;
            case 2:
                params.trueVal = 4.0 / 15.0;
                break;
            case 3:
                params.trueVal = 0.0;
                break;
        }
        if (params.equation == 1) {
            params.a = 0;
            params.b = 1;
            params.c = 0;
            params.d = 2;
        }
    }
}
