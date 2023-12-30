#include "main.h"

int shell_execute(char **args)
{
    pid_t pid;
    int status;

     if (args[0] != NULL && strcmp(args[0], "exit") == 0) {
        exit(0);
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("shell");
	     exit(2);
	}
            exit(EXIT_FAILURE); 
            } else if (pid < 0) {
        perror("shell");
    } else {
  
        waitpid(pid, &status, WUNTRACED);
        if (WIFEXITED(status)) {
            return WEXITSTATUS(status);
        }
    }

    return 1;
}
