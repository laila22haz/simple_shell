#include "simple_shell.h"

/**********laila & rabia**********/

/**
 * get_enviro - Retrieves the value of an environment variable.
 * @Var: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 *
 */

char *get_enviro(const char *Var)
{
	int i = 0;
	char *key;

	do {
		key = strtok(environ[i], "=");
		if (_strcmp(Var, key) == 0)
			return (strtok(NULL, "\n"));
	} while (environ[i++] != NULL);
	return (NULL);
}

