#include "simple_shell.h"

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
