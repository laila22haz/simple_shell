#include "simple_shell.h"
/**
 * _print - Prints a string.
 * @str: The string to be printed.
 *
 * Return: The number of characters printed.
 */
int _print(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
