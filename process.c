#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int processInput(char *input) {
    int retCode = 0;
    pid_t pID = fork();

    if (pID == -1) {
        perror("fork");
        free(input);
        exit(EXIT_FAILURE);
    } else if (pID == 0) {
        char *argsList[2];
        argsList[0] = input;
        argsList[1] = NULL;

        if (strcmp(input, "exit") == 0) {
            free(input);
            exit(0);
        }

        if (access(input, X_OK) == 0 && execve(input, argsList, environ) == -1) {
            perror("execve");
            free(input);
            exit(EXIT_FAILURE);
        }

        fprintf(stderr, "./shell: %s: not found\n", input);
        free(input);
        exit(127);
    } else {
        waitpid(pID, &retCode, 0);
        free(input);

        if (WIFEXITED(retCode)) {
            retCode = WEXITSTATUS(retCode);
        } else {
            retCode = 1;
        }
    }

    return retCode;
}
