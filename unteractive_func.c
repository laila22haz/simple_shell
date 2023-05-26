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
			rm_newline(lineptr);
			rm_cmt(lineptr);
			commands = tokenizer(lineptr, ";");
			while(commands[i] != NULL)
			{
				current_ = tokenizer(commands[i], " ");
				if (current_[0] == NULL)
				{
					free(current_);
					break;
				}
				typ_cmd = parse_command(current_[0]);
				initializer(current_, typ_cmd);
				free(current_);
			i++;
			}
			free(commands);
		}
		free(lineptr);
		exit(status);
	}
}
