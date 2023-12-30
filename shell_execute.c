#include "main.h"

/**
 * shell_execute - Execute a command given its arguments.
 *
 * This function takes an array of strings (command and its arguments) and
 * executes the command. If the command is "exit", the program exits.
 *
 * @args: An array of strings where the first element is the command and
 *        subsequent elements are arguments.
 *
 * Return: Always returns 1 to continue the shell loop.
 */

int shell_execute(char **args)
{

pid_t pid;
int status;

if (args[0] != NULL && strcmp(args[0], "exit") == 0)
{
exit(0);
}

pid = fork();
if (pid == 0)
{
if (execvp(args[0], args) == -1)
{
perror("shell");
}
exit(EXIT_FAILURE);
}
else if (pid < 0)
{
perror("shell");
}
else
{
do {
waitpid(pid, &status, WUNTRACED);
} while (!WIFEXITED(status) && !WIFSIGNALED(status));
}
return (1);
}
