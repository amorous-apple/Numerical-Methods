#include "utils_data.h"

// Creating the filename to write the data
char *create_filename(char *fileBase) {
    char *filename = malloc(200);
    snprintf(filename, 200, "./data/%s.csv", fileBase);

    return filename;
}

// Writing the data to file
void data_write(char *fileBase, double **data1, double **data2,
                double **data3) {
    char *filename = create_filename(fileBase);
    remove(filename);
    FILE *dstFile = fopen(filename, "a");
    if (dstFile == NULL) {
        perror("Error opening file\n");
    }

    for (int i = 0; i < NUM_STEPS; i++) {
        char dataLine[200];
        snprintf(dataLine, 200, "%lf,%lf,%lf,%lf\n", data1[i][0], data1[i][1],
                 data2[i][1], data3[i][1]);
        fprintf(dstFile, "%s", dataLine);
    }

    free(filename);
    fclose(dstFile);
}
