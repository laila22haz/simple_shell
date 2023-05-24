#include "simple_shell.h"
/**
 * main - check our simple shell
 *
 * Return: Always 0.
 */
int main(void)
{
	char *command;
	char *prompt = "cisfun$ ";
	size_t n = 0;
	int read;

	while (1)
	{
		_print(prompt);
		read = getline(&command, &n, stdin);
		if (read == -1)
		{
			_print("\n");
			free(command);
			exit(1);
		}
		execute_command(command);
		free(command);
		command = NULL;
	}
	return (0);
}
