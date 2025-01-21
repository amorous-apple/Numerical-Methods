#include "init.h"

int FUNC_ID;
int NUM_FUNCTIONS = 2;
int MIN_INTERVALS = 5;
int MAX_INTERVALS = 501;

void init(int argc, char **argv) {
    if (argc == 1) {
        FUNC_ID = 1;
    } else if (argc == 2) {
        FUNC_ID = atoi(argv[1]);
    } else {
        printf("Invalid number of command line arguments!\n");
        printf("Usage: ./integrate.out <ID of function to be integrated>\n");
        exit(EXIT_FAILURE);
    }
}

void init_integral(Integral *I) {
    switch (FUNC_ID) {
        case 1:
            I->fnctPtr = func1;
            I->ptA = 0.0;
            I->ptB = M_PI / 2.0;
            break;
        case 2:
            I->fnctPtr = func2;
            I->ptA = -1.0;
            I->ptB = 3.0;
            break;
        case 3:
            I->fnctPtr = func3;
            I->ptA = -1.0;
            I->ptB = 1.0;
            break;
    }

    I->dataX = malloc(MAX_INTERVALS * sizeof(double));
    I->dataY = malloc(MAX_INTERVALS * sizeof(double));
    if (I->dataX == NULL || I->dataY == NULL) {
        perror("Error allocating memory for I->dataX or I->dataY!\n");
        exit(EXIT_FAILURE);
    }
}

// Setting numPoints of dataX with an interval of h
double *setXVals(Integral *I) {
    double range = I->ptB - I->ptA;
    double h = range / (I->numPoints - 1);

    for (int i = 0; i < I->numPoints; i++) {
        I->dataX[i] = I->ptA + i * h;
    }

    return I->dataX;
}

// Seeting numPoints of dataY to the corresponding function value
double *setYVals(Integral *I) {
    for (int i = 0; i < I->numPoints; i++) {
        I->dataY[i] = I->fnctPtr(I->dataX[i]);
    }

    return I->dataY;
}
