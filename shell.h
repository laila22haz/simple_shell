#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <dirent.h>
#include <signal.h>
#include "myString.h"

extern char **environ;
extern char *lineptr;
extern char **commands;
extern char *name;
extern int status;

#define EXTEN_CMD 1
#define INTEN_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1

#define min(x, y) (((x) < (y)) ? (x) : (y))

/**
 *struct func_struct - a struct that maps a command name to a function 
 *
 *@name_cmd: name of the command
 *@func: the function that executes the command
 */
typedef struct func_struct
{
	char *name_cmd;
	void (*func)(char **cmd);
} struct_func;

/*helpers*/
char **tokenizer(char *, char *);
void remove_newline(char *);
char *_strtok_r(char *, char *, char **);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ctrl_c(int);
void remove_cmt(char *);

/*utils*/
int parse_command(char *);
void execute_command(char **, int);
char *check_path(char *);
void (*get_func(char *))(char **);
char *_getenv(char *);

/*built_in*/
void env_func(char **);
void exit_func(char **);

/*main*/
extern void non_interactive(void);
extern void init_func(char **current_, int typ_cmd);

#endif


