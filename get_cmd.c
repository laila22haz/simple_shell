#include "simple_shell.h"

/**
 * get_cmd - Searches for a command in the directories listed in the PATH.
 * @cmd: The name of the command to search for.
 *
 * Return: The full path of the command if found, NULL otherwise.
 */
char *get_cmd(char *cmd)
{
	char *path = get_enviro("PATH");
	char *dir;
	char *full_cmd;
	struct stat file_stat;

	dir = strtok(path, ":");
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
	return (NULL);
}
