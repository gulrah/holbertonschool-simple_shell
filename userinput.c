#include "main.h"

char *get_user_input(void) {
    char *buffer = NULL;
    size_t buffer_size = 0;
    ssize_t read_size = getline(&buffer, &buffer_size, stdin);

    if (read_size == -1) {
        free(buffer);
        return NULL;
    }

    if (buffer[read_size - 1] == '\n') {
        buffer[read_size - 1] = '\0';
    }

    return buffer;
}
