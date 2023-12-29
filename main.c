#include "main.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *command;

    while (1)
    {
        display_prompt();
        command = read_command();

        if (command == NULL)
        {
            break;
        }

        if (strcmp(command, "exit") == 0)
        {
            handle_exit();
            break;
        }
        else if (strcmp(command, "env") == 0)
        {
            handle_env();
        }
        else
        {
            execute_command(command);
        }

        free(command);
    }

    return (0);
}

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
    printf("$ ");
}

/**
 * read_command - Read a command from the user
 *
 * Return: The command string or NULL on EOF
 */
char *read_command(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;

    if (getline(&buffer, &bufsize, stdin) == -1)
    {
        free(buffer);
        return (NULL);
    }

    return (buffer);
}
