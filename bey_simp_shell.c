#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/**
 * main - Main Entry
 * @argc: num of argv
 * @argv: str of arg
 * @envp: for env only
 *
 * Return: always 0.
 */

int main(int argc, char *argv[], char *envp[])
{
	char *command;
	char *path;

	while (1)
	{
		command = read_input(argc, argv);
		if (command == NULL)
		{
			break;
		}
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "env") == 0)
		{
			print_env(envp);
			continue;
		}
		path = exe_command_path(command);
		if (path != NULL)
		{
			execute_command(command);
			free(path);
		}
		else
		{
			fprintf(stderr, "Command not found in path\n");
		}
		free(command);
		command = NULL;

	}
	return (0);
}
