#include "simple_shell.h"
int main(){
	char *command;
	char *prompt = "cisfun$ ";
	size_t n = 0;
	int read;
	while (1) {
		_print(prompt);
		read = getline(&command, &n, stdin);
		if (read == -1)
		{
			return (-1);
		}
		execute_command(command);
		free(command);
	}
	return 0;
}
