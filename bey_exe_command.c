#include "main.h"

/**
 * execute_command - my literal engine
 *
 * @command: a ptr
 */

void execute_command(char *command)
{
	char **args = handle_arguments(command);
	pid_t pid = fork();
	int status;

	if (strcmp(command, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}

	if (args == NULL)
	{
		fprintf(stderr, "Error allocating mem for args\n");
		exit(EXIT_FAILURE);
	}

	if (pid == -1)
	{
		fprintf(stderr, "Error forking\n");
		free_arguments(args);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/**if (execve(args[0], args, NULL) == -1)*/
		if (execvp(args[0], args) == -1)
		{
			fprintf(stderr, "./hsh: No such file or directory\n");
			free_arguments(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(pid, &status, 0);
		free_arguments(args);
	}
}
/**
 * print_env - printing the enviroment
 * @envp: i'm gonna be passing it to my main funtion since
 * i can't use extern.
 */
void print_env(char **envp)
{
	char **env;

	for (env = envp; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}
