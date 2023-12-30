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
char *line = NULL; /* Pointer to store the line */
size_t bufsize = 0; /* Buffer size for getline */
printf(":) ");
getline(&line, &bufsize, stdin);
return (line);
}

/**
 * handle_input - Handle the input string from the user.
 *
 * This function takes a string as input and checks for specific commands
 * such as "exit". If the input matches the exit command, the program exits.
 *
 * @input_str: The input string from the user.
 *
 * Return: 1 if the input was handled and the program should continue,
 *         0 if the input was NULL.
 */

int handle_input(char *input_str)
{
if (input_str == NULL)
{
return (0);
}

if (strcmp(input_str, "exit\n") == 0)
{
free(input_str);
exit(0);
}

return (1);
}
/**
 * free_line - Free memory allocated for a line.
 *
 * This function takes a pointer to a line and frees the memory allocated
 * for it using the free() function.
 *
 * @line: Pointer to the line that needs to be freed.
 */

void free_line(char *line)
{
free(line);
}
