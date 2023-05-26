#include "shell.h"


char **commands = NULL;
char *lineptr = NULL;
char *name = NULL;
int status = 0;

/**
 * main - the main function
 * @argc: number of arguments
 * @argv: arguments to be parsed
 *
 * Return: 0 on success
 */


int main(int argc, char **argv)
{
	char **current_ = NULL;
	int i, typ_cmd = 0;
	size_t n = 0;

	(void)argc;
	signal(SIGINT, ctrl_c);
	name = argv[0];
	while (1)
	{
		uninteractive();
		_puts(" ($) ", STDOUT_FILENO);
		if (getline(&lineptr, &n, stdin) == -1)
		{
			free(lineptr);
			exit(status);
		}
			remove_N(lineptr);
			remove_cmt(lineptr);
			commands = _split(lineptr, ";");

		i = 0;
		while (commands[i] != NULL)
		{
			current_ = _split(commands[i], " ");
			if (current_[0] == NULL)
			{
				free(current_);
				break;
			}
			typ_cmd = cmd_type(current_[0]);

			init_func(current_, typ_cmd);
			free(current_);
		i++;
		}
		free(commands);
	}
	free(lineptr);

	return (status);
}
