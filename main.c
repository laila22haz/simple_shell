#include "simple_shell.h"
/********work team laila & rabia ***************/

/**
 * main - check our simple shell
 *
 * Return: Always 0.
 */

int main(void)
{
	char *command = NULL;
	char *prompt = "cisfun$ ";
	size_t n = 0;
	int read;

	while (1)
	{
		_print(prompt);
		read = getline(&command, &n, stdin);
		if (read <= 0)
		{
			free(command);
			exit(1);
		}
		if ((read == 1 && command[0] == '\n') || check_blank(command) == 0)
			continue;
		execute_command(command);
		free(command);
		command = NULL;
	}
	return (0);
}
