#include "utils.h"

FILE *opfile(const char *filename) {
    // Opening a file to write the calculated data
    FILE *pfile = fopen(filename, "a");
    if (pfile == NULL) {
        perror("File not found!\n");
        exit(EXIT_FAILURE);
    }
    return pfile;
}
