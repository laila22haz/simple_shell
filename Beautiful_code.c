#include "simple_shell.h"

/**********laila & rabia**********/

/**
 * execute_command - function that execute our command
 * @command: command that will be execute
 * Return: void
 *
 */

void execute_command(char *command)
{
	pid_t pid;
	char **argv = NULL;
	char *ter = NULL;
	int status = 0;

	pid = fork();
	argv = _split(command, " \t\"\'\n");
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	if (pid < 0)
		perror("Fork failed");
	else if (pid == 0)
	{
		ter = get_cmd(argv[0]);
		if (!ter || execve(ter, argv, environ) == -1)
			perror(":( ");
		free(command);
		free(argv);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(&status);
		free(ter);
		free(argv);
	}

}
