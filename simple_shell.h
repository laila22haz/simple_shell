#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
extern char **environ;
int _print(char *str);
int _putchar(char c);
char *get_enviro(const char *Var);
char *get_cmd(char *cmd);
char **_split(char *input, char *delim);
void execute_command(char *command);
#endif
