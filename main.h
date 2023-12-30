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

#endif /* MAIN_H */
