#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


int processInput(char *input);
char *get_user_input(void);
void tokenize_input(char *input_str, char **arg_list);
int handle_input(char *input_str);
int shell_loop(void);
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_execute(char **args);

#endif /* MAIN_H */
