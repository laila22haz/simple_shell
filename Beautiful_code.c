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

	pid = fork();
	argv = _split(command, " \t\"\'\n");
	if (_strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	if (pid < 0)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		if (_strcmp(argv[0], "ls") == 0 || _strcmp(argv[0], "/bin/ls") == 0)
			execve("/bin/ls", argv, environ);
		else
		{
			ter = get_cmd(argv[0]);
			if (!ter || execve(ter, argv, environ) == -1)
				perror(":( ");
			free(command);
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
		free(ter);
		free(argv);
	}

}
