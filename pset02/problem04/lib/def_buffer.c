#include "def_buffer.h"

char *def_buffer(void) {
    // Defining a buffer to store all data during runtime
    char *BigBuff = malloc(params.MAX_BUFFER_SIZE);
    if (BigBuff == NULL) {
        perror("Failure allocating memory!");
        exit(EXIT_FAILURE);
    }
    return BigBuff;
}
