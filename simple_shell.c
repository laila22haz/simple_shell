#include "shell.h"

/**
 * cmd_type - Parses the command and determines its type
 * @cmd: Command string
 *
 * Return: Type of the command
 */

int cmd_type(char *cmd)
{
	int i = 0;
	char *intern_cmd[] = {"env", "exit", NULL};
	char *path = NULL;

	while (cmd[i] != '\0')
	{
		if (cmd[i] == '/')
			return (EXTEN_CMD);
		i++;
	}
	for (i = 0; intern_cmd[i] != NULL; i++)
	{
		if (_strcmp(cmd, intern_cmd[i]) == 0)
			return (INTEN_CMD);
	}
	path = get_cmd(cmd);
	if (path != NULL)
	{
		free(path);
		return (PATH_CMD);
	}

	return (INVALID_CMD);
}

/**
 * execute_command - Executes the command based on its type
 * @token_cmd: Tokenized command arguments
 * @check_command: Type of the command
 * Return: void
 */
void execute_command(char **token_cmd, int check_command)
{
	void (*func)(char **cmd);

	if (check_command == EXTEN_CMD)
	{
		if (execve(token_cmd[0], token_cmd, NULL) == -1)
		{
			perror(get_enviro("PWD"));
			exit(2);
		}
	}
	if (check_command == PATH_CMD)
	{
		if (execve(get_cmd(token_cmd[0]), token_cmd, NULL) == -1)
		{
			perror(get_enviro("PWD"));
			exit(2);
		}
	}
	if (check_command == INTEN_CMD)
	{
		func = get_func(token_cmd[0]);
		func(token_cmd);
	}
	if (check_command == INVALID_CMD)
	{
		_puts(name, STDERR_FILENO);
		_puts(": 1: ", STDERR_FILENO);
		_puts(token_cmd[0], STDERR_FILENO);
		_puts(": not found\n", STDERR_FILENO);
		status = 127;
	}
}

/**
 * get_cmd - Searches for a command in the directories listed in the PATH.
 * @cmd: The name of the command to search for.
 *
 * Return: The full path of the command if found, NULL otherwise.
 *
 */

char *get_cmd(char *cmd)
{
	char *path = get_enviro("PATH");
	char *dir;
	char *full_cmd, *copy;
	struct stat file_stat;

	copy = malloc(sizeof(char) * (_strlen(path) + 1));
	_strcpy(copy, path);

	dir = strtok(copy, ":");
	while (dir)
	{
		full_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		_strcpy(full_cmd, dir);
		_strcat(full_cmd, "/");
		_strcat(full_cmd, cmd);
		if (stat(full_cmd, &file_stat) == 0)
			return (full_cmd);
		free(full_cmd);
		dir = strtok(NULL, ":");
	}
	if (stat(cmd, &file_stat) == 0)
		return (cmd);
	return (NULL);
}
/**
 * get_func - function based on the command given
 * @cmd: first argument
 *
 * Return: pointer,  null otherwise
 */
void (*get_func(char *cmd))(char **)
{
	int i;
	
	struct_func mapping[] = {
		{"env", env_func}, {"exit", exit_func}
	};

	for (i = 0; i < 2; i++)
	{
		if (_strcmp(cmd, mapping[i].name_cmd) == 0)
			return (mapping[i].func);
	}
	return (NULL);
}

/**
 * get_enviro - Retrieves the value of an environment variable.
 * @Var: The name of the environment variable.
 *
 * Return: The value of the environment variable if found, NULL otherwise.
 *
 */

char *get_enviro(const char *Var)
{
	int i = 0;
	char *key = NULL;

	do {
		key = strtok(environ[i], "=");
		if (_strcmp(Var, key) == 0)
			return (strtok(NULL, "\n"));
	} while (environ[i++] != NULL);
	return (NULL);
}
