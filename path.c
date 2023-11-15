#include "main.h"
/**
 * exe_command_path - path
 * @command: ptr command
 * Return: path mem
 */
char *exe_command_path(char *command)
{
	char *path = getenv("PATH");
	char *a_m = strdup(path);
	char *sep = strtok(a_m, ":");
	char *f_p = NULL;

	while (sep != NULL)
	{
		f_p = malloc(strlen(sep) + strlen(command) + 2);
		/**sprintf(f_p, "%s/%s", sep, command);*/
		if (f_p == NULL)
		{
			fprintf(stderr, "Error allocating mem\n");
			free(a_m);
			return (NULL);
		}
		sprintf(f_p, "%s/%s", sep, command);
		if (access(f_p, X_OK) == 0)
		{
			free(a_m);
			return (f_p);
		}
		free(f_p);
		sep = strtok(NULL, ":");
	}
	free(a_m);
	return (NULL);
}
