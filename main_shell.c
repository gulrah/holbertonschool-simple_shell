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

#include "main.h"

int main(void) {
    if (isatty(STDIN_FILENO)) {
       return shell_loop();
    } else {
        char *line = NULL;
        size_t len = 0;
        ssize_t read;

            while ((read = getline(&line, &len, stdin)) != -1) {
            handle_input(line);
        }

        free(line);
        return 0;
    }
}
