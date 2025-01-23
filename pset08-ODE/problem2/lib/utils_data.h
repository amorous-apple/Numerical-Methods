#ifndef UTILS_DATA_H
#define UTILS_DATA_H

#include <stdlib.h>
#include <stdio.h>

#include "init.h"

char *create_filename(char *fileBase);
void data_write(char *fileBase, double **data1, double **data2, double **data3);

#endif
