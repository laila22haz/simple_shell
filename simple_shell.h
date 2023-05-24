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
int check_blank(char *input);
char *_strcat(char *dest, char *src);
int _strcmp(const char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *get_enviro(const char *Var);
char *get_cmd(char *cmd);
char **_split(char *input, char *delim);
void execute_command(char *command);
#endif
