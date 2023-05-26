#include "shell.h"
/**
 *prompt - gives a prompt on the shell
 *@av: arguement vector
 *@env: environment vector
 *Return: return pid
 */

int prompt(char **av, char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t get_char;
	pid_t childprog;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			_put("shellinput$ ");
		}
		get_char = getline(&input, &input_size, stdin);
		if (get_char == -1)
		{
			perror("");
			return (0);
		}
		if (input[get_char - 1] == '\n')
			input[get_char - 1] = '\0';
		childprog = fork();
		if (childprog == -1)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
		if (childprog == 0)
			executer(input, av, env);
		else
		{
			int status;

			waitpid(childprog, &status, 0);
		}
	}
	free(input);
	return (0);
}
