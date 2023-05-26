#include "shell.h"

/**
 * uninteractive - Executes commands in non-interactive mode
 * Return: void
 */

void uninteractive(void)
{
	char **current_ = NULL;
	int i = 0, typ_cmd = 0;
	size_t n = 0;

	if (isatty(STDIN_FILENO) == 1)
	{
		while (getline(&lineptr, &n, stdin) != -1)
		{
			remove_N(lineptr);
			remove_cmt(lineptr);
			commands = _split(lineptr, ";");
			while(commands[i] != NULL)
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
		exit(status);
	}
}
