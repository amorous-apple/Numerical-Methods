#include "init.h"

Parameters params;
void init(int argc, char **argv) {
    if (argc != 1 && argc != 6) {
        printf("Incorrect number of arguments!\n");
        printf(
            "Usage: ./qmapp <integrationMethod> <functionName> <lowerBound> "
            "<upperBound> "
            "<numPoints>\n");
        exit(EXIT_FAILURE);
    } else if (argc == 1) {
        params.method = "newton";
        params.function = "fx1";
        params.a = 0.0;
        params.b = 1.0;
        params.numPoints = 5;
    } else {
        params.method = argv[1];
        params.function = argv[2];
        params.a = atof(argv[3]);
        params.b = atof(argv[4]);
        params.numPoints = atoi(argv[5]);
    }
}
