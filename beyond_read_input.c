#include "main.h"
/**
 * read_input - addressing args
 * @argc: num of args in a str
 * @argv: str in an agr
 * Return: success always.
 */
char *read_input(int argc, char *argv[])
{
	size_t s = 0;
	char *input = NULL;
	ssize_t characters;
	(void)argc;
	(void)argv;

	while (1)
	{
		printf("%s", PROMPT);
		fflush(stdout);
		characters = getline(&input, &s, stdin);
		if (characters == -1)
		{
			if (feof(stdin))
			{
				free(input);
				return (NULL);
			}
			else
			{
			fprintf(stderr, "Error reading input\n");
			free(input);
			return (NULL);
			}
		}
		if (characters > 0 && input[characters - 1] == '\n')
		{
			input[characters - 1] = '\0';
		}
		if (input != NULL)
		{
			execute_command(input);
		}
		free(input);
		input = NULL;
	}
	return (input);
}
