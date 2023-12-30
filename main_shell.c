#include "main.h"

/**
 * shell_loop - Main loop for the shell. Continuously prompts the user for
 *  processes the input, and executes commands.
 *
 * Return: Always returns 0 upon successful completion.
 */

int shell_loop(void)
{
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
}
while (status);
return (0);
}


/**
 * main - Entry point for the shell program. Calls the main loop of the shell.
 *
 * Return: Always returns the value returned by shell_loop(), which is 0.
 */

int main(void)
{
return (shell_loop());
}
