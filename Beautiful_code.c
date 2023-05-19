#include "simple_shell.h"

/**
 * execute_command - function that execute our command
 * @command: command that will be execute
 * Return: void
 */
void execute_command(char *command)
{
	pid_t pid = fork();
	char **argv;

	if (pid < 0)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		argv = _split(command);
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("./hsh");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
	}

}
