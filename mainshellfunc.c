#include "shell.h"

#define MAX_COMMAND 10

/**
 *shprompt - gives a prompt on the shell
 *@av: arguement vector
 *@env: environment vector
 *Return: return pid
 */

void shprompt(char **av, char **env)
{
	char *inputstrng = NULL;
	int i, j, status;
	size_t n = 0;
	ssize_t get_char;
	char *argv[MAX_COMMAND];
	pid_t childpid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("shellinput$ ");
		get_char = getline(&inputstrng, &n, stdin);
		if (get_char == -1)
		{
			free(inputstrng);
			exit(EXIT_FAILURE);
		}
		i = 0;
		if (inputstrng[i] == '\n')
		{
			inputstrng[i] = 0;
			i++;
		}
		j = 0;
		argv[j] = strtok(inputstrng, " ");
		while (argv[j])
			argv[++j] = strtok(NULL, " ");
		childpid = fork();
		if (childpid == -1)
		{
			free(inputstrng);
			exit(EXIT_FAILURE);
		}
		if (childpid == 0)
		{
			if (execve(argv[0], argv, env) == -1)
				_puts("no such file or directory");
		}
		else
			wait(NULL);
	}
	return (childpid);
}
