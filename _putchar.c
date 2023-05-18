#include "simple_shell.h"
/**
* _putchar - write character into the standard output
* @c: character
*
* Return: character printed
*/

int _putchar(char c)
{
        return (write(1, &c, 1));
}
