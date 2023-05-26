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


#define EXTEN_CMD 1
#define INTEN_CMD 2
#define PATH_CMD 3
#define INVALID_CMD -1



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



extern char **environ;
extern char *lineptr;
extern char **commands;
extern char *name;
extern int status;




char **_split(char *, char *);
void remove_N(char *);
void ctrl_c(int);
void remove_cmt(char *);


int cmd_type(char *);
void execute_command(char **, int);
char *get_cmd(char *);
void (*get_func(char *))(char **);
char *get_enviro(const char *);


void env_func(char **);
void exit_func(char **);


extern void uninteractive(void);
extern void init_func(char **current_, int typ_cmd);

#endif


