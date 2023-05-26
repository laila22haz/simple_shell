#include "shell.h"

/**
 * env_func - Prints the environment variables
 * @token_cmd: Unused parameter
 *
 * Return : void
 */

void env_func(char **token_cmd)
{
	int i = 0;
	
	(void)token_cmd;

	while(environ[i] != NULL)
	{
		_puts(environ[i], STDOUT_FILENO);
		_puts("\n", STDOUT_FILENO);
		i++;
	}
}

/**
 * exit_func - Exits the shell program
 * @token_cmd: Tokenized command arguments
 *
 * Return: void
 */
void exit_func(char **token_cmd)
{
	int i = 0, arg;

	for(;token_cmd[i] != NULL; i++)
		;
	if (i == 1)
	{
		free(token_cmd);
		free(lineptr);
		free(commands);
		exit(status);
	}
	else if (i == 2)
	{
		arg = _atoi(token_cmd[1]);
		if (arg == -1)
		{
			_puts(shell_name, STDERR_FILENO);
			_puts(": 1: exit: Illegal number: ", STDERR_FILENO);
			_puts(tokenized_command[1], STDERR_FILENO);
			_puts("\n", STDERR_FILENO);
			status = 2;
		}
		else
		{
			free(line);
			free(token_cmd);
			free(commands);
			exit(arg);
		}
	}
	else
		_puts("$: exit doesn't take more than one argument\n", STDERR_FILENO);
}
