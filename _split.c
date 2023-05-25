#include "simple_shell.h"

/**
 * _split - Split a string into an array of tokens based on a delimiter.
 * @input: The input string to split.
 * @delim: The delimiter used to split the string.
 *
 * Return: An array of tokens if successful, NULL otherwise.
 */
char **_split(char *input, char *delim)
{
	char **argv = NULL;
	char *token = NULL;
	int i = 0;

	argv = malloc(sizeof(char *) * 1024);
	if (argv == NULL)
	{
		perror("failed");
		exit(EXIT_FAILURE);
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i++] = token;
		if (argv[i - 1] == NULL)
		{
			perror("Allocation failed");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
