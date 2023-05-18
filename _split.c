#include "simple_shell.h"

char **_split(char *input)
{
	char **argv;
	char *token;
	int i = 0;
	const char *delim = " \t\n";

	argv = malloc(sizeof(char*) * 1024);
	if(argv == NULL)
	{
		perror("failed");
	}
	token = strtok(input, delim);
	while (token != NULL)
	{
		argv[i++] = token;
		token = strtok(NULL, delim);
	}
	i++;
	argv = malloc(sizeof(char *) * i);
	token = strtok(input, delim);
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		argv[i] = token;
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return (argv);
}
