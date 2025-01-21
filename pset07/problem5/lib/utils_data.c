#include "utils_data.h"

// Creating the filename to write the data
char *create_filename(void) {
    char *filename = malloc(200);
    snprintf(filename, 200, "./data/function%d.csv", FUNC_ID);

    return filename;
}

// Writing the data for the function error to file
void data_write(double *ls_logh, double **ls_logE) {
    char *fileName = create_filename();
    remove(fileName);
    FILE *dstFile = fopen(fileName, "a");
    if (dstFile == NULL) {
        perror("Error opening file\n");
    }

    for (int i = MIN_INTERVALS; i <= MAX_INTERVALS; i++) {
        char dataLine[200];
        snprintf(dataLine, 200, "%d,%.3lf,%.3lf,%.3lf\n", i, ls_logh[i],
                 ls_logE[i][0], ls_logE[i][1]);
        fprintf(dstFile, "%s", dataLine);
    }
}
