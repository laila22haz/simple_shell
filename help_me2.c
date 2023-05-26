#include "shell.h"

/**
 * ctrl_c - handles the signal raised by CTRL-C
 * @signum: signal number
 *
 * Return: void
 */
void ctrl_c(int signum)
{
	if (signum == SIGINT)
		print("\n($) ", STDIN_FILENO);
}
/**
 * remove_cmt - removes/ignores everything after a '#' char
 * @input: input to be used
 *
 * Return: void
 */
void remove_cmt(char *input)
{
	int i = 0;

	if (input[i] == '#')
		input[i] = '\0';
	while (input[i] != '\0')
	{
		if (input[i] == '#' && input[i - 1] == ' ')
			break;
		i++;
	}
	input[i] = '\0';
}
/**
 *remove_N - removes new line from a string
 *@str: string to be used
 *
 *
 *Return: void
 */

void remove_N(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			break;
		i++;
	}
	str[i] = '\0';
}
