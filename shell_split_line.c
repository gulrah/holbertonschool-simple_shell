#include "main.h"

#define TOK_DELIM " \t\r\n"

/**
 * shell_split_line - Split a string into tokens.
 *
 * This function takes a string and splits it into tokens based on the
 * specified delimiters. The tokens are returned as an array of strings.
 *
 * @line: The input string to be split.
 *
 * Return: An array of tokens (strings) terminated by a NULL pointer.
 */

char **shell_split_line(char *line)
{
int bufsize = 64;
int position = 0;
char **tokens = malloc(bufsize * sizeof(char *));
char *token;

if (!tokens) {
fprintf(stderr, "shell: allocation error\n");
exit(EXIT_FAILURE);
}

token = strtok(line, TOK_DELIM);
while (token != NULL) {
tokens[position] = token;
position++;
if(position >= bufsize) {
bufsize += 64;
tokens = realloc(tokens, bufsize * sizeof(char *));
if (!tokens) {
fprintf(stderr, "shell: allocation error\n");
exit(EXIT_FAILURE);
}
}

token = strtok(NULL, TOK_DELIM);
}
tokens[position] = NULL;
return (tokens);
}
