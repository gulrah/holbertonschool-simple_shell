#include "main.h"

int shell_loop(void) {
    int pipe_status = !isatty(fileno(stdin));
    char *input;

    while (1) {
        if (!pipe_status) {
            printf("#shell$ ");
            fflush(stdout);
        }

        input = get_user_input();
        if (input == NULL) {
            break;
        }

        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(0);
        }

        int status = NULL;
	status = handle_input(input);

        if (status == 2 && pipe_status) {
            exit(2);
        }
    }

    return 0;
}

int main(void) {
    return shell_loop();
}
