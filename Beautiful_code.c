#include "simple_shell.h"
int execute_command(char *command)
{
	pid_t pid = fork();
	char **argv;

	if (pid < 0)
	{
		perror("Fork failed");
		return (-1);
	}
	else if (pid == 0)
	{
		argv = _split(command);
		if(execve(argv[0], argv, NULL)== -1)
		{
			perror("./hsh");
		}
	}
	else
	{
		wait(NULL);
	}
	return 0;
}
