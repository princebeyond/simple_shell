#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

/**
 * handle_arguments - handlingg ars
 *
 * @command: ptr TO COMMAND.
 * Return: args.
 */
/**void execute_command(char *command)*/
char **handle_arguments(char *command)
{
	int argc = 100;
	char **args = malloc((argc + 1) * sizeof(char *));
	char *token = strtok(command, " ");
	int idx = 0;


	while (token != NULL)
	{
		args[idx] = strdup(token);
		if (args[idx] == NULL)
		{
			fprintf(stderr, "Error allocating memory args[idx]\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, " ");
		idx++;
	}
	args[idx] = NULL;
	return (args);
}
/**
 * free_arguments - still wondering why all my args anit free yet
 * @args: args to be freed
 */
void free_arguments(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
