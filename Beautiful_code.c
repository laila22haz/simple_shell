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
	char *ter;

	argv = _split(command, " \t\n");
	if (strcmp(argv[0], "exit") == 0)
	{
		exit(0);
	}
	if (pid < 0)
	{
		perror("Fork failed");
	}
	else if (pid == 0)
	{
		if (strcmp(argv[0], "ls") == 0 || strcmp(argv[0], "/bin/ls") == 0)
			execve("/bin/ls", argv, environ);
		else
		{
			ter = get_cmd(argv[0]);
			if (!ter || execve(ter, argv, environ) == -1)
				perror(":( ");
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

}
