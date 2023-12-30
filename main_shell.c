#include "main.h"

int shell_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf(":) ");
        line = shell_read_line();
        args = shell_split_line(line);
        status = shell_execute(args);

        free(line);
        free(args);
    } while (status);

    return 0; 
}

int main(void) {
    return shell_loop();
}
