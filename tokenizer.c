#include "main.h"

void tokenize_input(char *input_str, char **arg_list) {
    int arg_count = 0;
    char *token = strtok(input_str, " ");

    while (token != NULL && arg_count < 63) {
        arg_list[arg_count++] = token;
        token = strtok(NULL, " ");
    }

    arg_list[arg_count] = NULL;
}
