#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024


void display_prompt(void);
char *read_command(void);
void execute_command(char *command);
void handle_exit(void);
void handle_env(void);
void handle_error(char *program_name, char *error_message);

#endif /* _MAIN_H_ */
