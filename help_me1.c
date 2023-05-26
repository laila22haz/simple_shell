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
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int l = 0;
	int x = 0;

	while (*(src + l) != '\0')
	{
		l++;
	}
	for ( ; x < l ; x++)
	{
		dest[x] = src[x];
	}
	dest[l] = '\0';
	return (dest);
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
char *_strtok_r(char *string, char *delim, char **save_ptr)
{
	char *finish;

	if (string == NULL)
		string = *save_ptr;

	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	string += _strspn(string, delim);
	if (*string == '\0')
	{
		*save_ptr = string;
		return (NULL);
	}

	finish = string + _strcspn(string, delim);
	if (*finish == '\0')
	{
		*save_ptr = finish;
		return (string);
	}

	*finish = '\0';
	*save_ptr = finish + 1;
	return (string);
}

/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
    int i, d, n, len, f, digit;

    i = 0;
    d = 0;
    n = 0;
    len = 0;
    f = 0;
    digit = 0;
    while (s[len] != '\0')
    len++;
    while (i < len && f == 0)
    {
    if (s[i] == '-')
    ++d;
    if (s[i] >= '0' && s[i] <= '9')
    {
    digit = s[i] - '0';
    if (d % 2)
    digit = -digit;
    n = n * 10 + digit;
    f = 1;
    if (s[i + 1] < '0' || s[i + 1] > '9')
    break;
    f = 0;
    }
    i++;
    }

    if (f == 0)
    return (0);

    return (n);
}
