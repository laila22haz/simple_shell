#include "simple_shell.h"
/**
 * _split - A function that splits a string into slices.
 * @input: The string to be split.
 * Return: An array of slices.
 */
char **_split(char *input)
{
	char **argv;
	char *token;
	int i = 0;
	const char *delim = " \t\n";

	argv = malloc(sizeof(char *) * 1024);
	if (argv == NULL)
	{
		perror("failed");
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
