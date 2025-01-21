#include "functions.h"

// Declaring functions to be integrated and their fourth derivatives
double fx1(double x) { return x + pow(x, 3); }
double d4fx1(double x) { return 0; }

double fx2(double x) { return x; }

// Creating a lookup table to match function names to their function pointers
FunctionMap funcTable[] = {{"fx1", &fx1}, {"fx1", &fx2}, {NULL, NULL}};
FunctionMap d4funcTable[] = {{"fx1", &d4fx1}, {NULL, NULL}};

// Returning a function's pointer given its name
funcPtr getFuncPtr(char *funcName) {
    for (int i = 0; funcTable[i].funcName != NULL; i++) {
        if (strcmp(funcName, funcTable[i].funcName) == 0) {
            return funcTable[i].func;
        }
    }
    return NULL;
}

// Returning a the pointer to the fourth derivative of a function given its name
funcPtr getd4FuncPtr(char *funcName) {
    for (int i = 0; d4funcTable[i].funcName != NULL; i++) {
        if (strcmp(funcName, d4funcTable[i].funcName) == 0) {
            return d4funcTable[i].func;
        }
    }
    return NULL;
}
