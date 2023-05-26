#include "shell.h"

/**
 *_puts - prints a string to stdout
 *@string: first arg
 *@stream: second arg
 *
 *Return: void
 */
void _puts(char *string, int stream)
{
	int i = 0;

	while (string[i] != '\0')
	{
		write(stream, &string[i], 1);
		i++;
	}
}


/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @source: copy to
 * @dest: copy from
 * Return: string
 */

void _strcpy(char *source, char *dest)
{
	int i = 0;

	while (source[i] != '\0')
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
}

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i;

	if (string == NULL)
		return (len);
	for (i = 0; s[i] != '\0'; i++)
		;
	return (i);
}
/**
 *_strtok_r - tokenizes a string
 *@string: string to be tokenized
 *@delim: delimiter to be used to tokenize the string
 *@save_ptr: pointer to be used to keep track of the next token
 *
 *Return: The next available token
 */


/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	unsigned int n = 0;

	do {
		if (*s == '-')
			return (-1);
		else if ((*s < '0' || *s > '9') && *s != '\0')
			return (-1);
		else if (*s >= '0'  && *s <= '9')
			n = (n * 10) + (*s - '0');
		else if (n > 0)
			break;
	} while (*s++);
	return (n);
}
