#include "main.h"
/**
 *handle_input - A function that handles console inputs to analyze
 *
 *
 */
int handle_input(char *input_str) {
	int return_status = 0;
	pid_t child_pid = fork();
	char *path = NULL;
	char *path_section = NULL;
	if (child_pid == -1) {
	perror("fork");
	free(input_str);
	exit(EXIT_FAILURE);
	} else if (child_pid == 0) {
	char *arguments[64];
	char **environ;

	tokenize_input(input_str, arguments);

	if (arguments[0] == NULL) {
		free(input_str);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(arguments[0], "env") == 0) {
		char **environment = environ;
		
		while (*environment != NULL) {
		printf("%s\n", *environment);
		environment++;
            }
            free(input_str);
            exit(EXIT_SUCCESS);
        }	
	path = getenv("PATH");

        if (path == NULL) {
            fprintf(stderr, "./hsh: 1: %s: not found\n", arguments[0]);
            free(input_str);
            exit(127);
        }

        path_section = strtok(path, ":");
        while (path_section != NULL) {
            char full_path[256];
            snprintf(full_path, sizeof(full_path), "%s/%s", path_section, arguments[0]);

            if (access(full_path, X_OK) == 0 && execve(full_path, arguments, environ) == -1) {
                perror("execve");
                free(input_str);
                exit(EXIT_FAILURE);
            }

            path_section = strtok(NULL, ":");
        }

        fprintf(stderr, "./hsh: 1: %s: not found\n", arguments[0]);
        free(input_str);
        exit(127);
    } else {
        waitpid(child_pid, &return_status, 0);
        free(input_str);

        if (WIFEXITED(return_status)) {
            return_status = WEXITSTATUS(return_status);
        } else {
            return_status = 1;
        }
    }

    return return_status;
}
