#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
int _print(char *str);
int _putchar(char c);
char **_split(char *input);
int execute_command(char *command);
#endif
