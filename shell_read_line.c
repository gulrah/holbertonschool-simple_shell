#include "main.h"

/**
 * shell_read_line - Read a line from the standard input.
 *
 * This function prompts the user with ":) " and reads a line of input from
 * the standard input (stdin).
 *
 * Return: The line of input read from stdin.
 */

char *shell_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0; 
   printf(":) ");
    getline(&line, &bufsize, stdin);
    return line;
}


int handle_input(char *input_str) {
    if (input_str == NULL) {
        return 0; 
    }

    
    if (strcmp(input_str, "exit\n") == 0) {
        free(input_str); 
        exit(0); 
    }



    return 1;
}
void free_line(char *line) {
    free(line);
}
