#include "shell.h"


/**
 * _strspn - function that gets the length of a prefix substring
 * @s: first value -char
 * @accept: second value - char
 *
 * Return: char with result
 */
unsigned int _strspn(char *s, char *accept)
{
    int j = 0, i = 0;
    unsigned int a = 0;

    while (s[i] != ' ' && s[i] != '\0')
    {
    while (accept[j] != '\0')
    {
    if (s[i] == accept[j])
    a++;
    j++;
    }
    i++;
    j = 0;
    }
    return (a);
}

/**
 *_strcspn - computes segment of str1 which consists of characters not in str2
 *@str1: string to be searched
 *@str2: string to be used
 *
 *Return: index at which a char in str1 exists in str2
 */


int _strcspn(char *str1, char *str2)
{
	int len = 0, i;

	for (i = 0; str1[i] != '\0'; i++)
	{
		if (_strchr(str2, str1[i]) != NULL)
			break;
		len++;
	}
	return (len);
}



/**
 * _strchr - function that locates a character in a string
 * @s: first value -char
 * @c: second value - char
 *
 * Return: char with result
 */
char *_strchr(char *s, char c)
{

    if (*s == '\0')
    return (s);
    while (*s)
    {
    if (*s == c)
    {
    return (s);
    }
    s++;
    }
    if (c == '\0')
    return (s);
    return ('\0');
}
/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
    int i;
    int j;

    i = 0;
    while (dest[i] != '\0')
    {
        i++;
    }
    j = 0;
    while (src[j] != '\0')
    {
        dest[i] = src[j];
        i++;
        j++;
    }

    dest[i] = '\0';
    return (dest);
}
/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            return (s1[i] - s2[i]);
        }
        i++;
    }
    return (0);
}




