#include "main.h"

char *shell_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0; 
    getline(&line, &bufsize, stdin);
    return line;
}
