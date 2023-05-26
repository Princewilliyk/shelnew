#include "shell.h"

/**
 *executer - gives a prompt on the shell
 *@argv: input arguement
 *@argment: programme input
 *@env: environment vector
 *Return: return 0
 */

void executer(char *argment, char **argv, char **env)
{
	argv = _strtok(argment, " ");

	if (execve(argv[0], argv, env) == -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
}
