#include "shell.h"

 /**
 * init_func - Initializes and executes a command
 * @current_: Current command arguments
 * @typ_cmd: Type of the command
 *
 * Return: void function
 */

void init_func(char **current_ , int typ_cmd)
{
	pid_t child_pid;

	if (typ_cmd == EXTEN_CMD || typ_cmd == PATH_CMD)
	{
		child_pid = fork();
		if (child_pid == 0)
			execute_command(current_, typ_cmd);
		else
		{
			waitpid(child_pid, &status, 0);
			status >>= 8;
		}
	}
	else
		execute_command(current_, typ_cmd);
}
