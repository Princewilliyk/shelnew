#include "shell.h"

/**
 *main - gives a prompt on the shell
 *@argc: arguement count
 * @argv: arguement vector
 *@env: environment vector
 *Return: return pid
 */

int main(int argc, char *argv[], char **env)
{
	char *input = NULL;
	size_t input_size = 0;
	ssize_t get_char;
	pid_t childprog;
	int status;
	bool from_pipe = true;
	(void)argc;

	while (1 || !from_pipe)
	{
		if (isatty(STDIN_FILENO == 0))
		{
			from_pipe = true;
			_put("shellinput$ ");
		}
		get_char = getline(&input, &input_size, stdin);
		if (get_char == -1)
		{
			perror("Error (getline)");
			free(input);
			exit(EXIT_FAILURE);
		}
		if (input[get_char - 1] == '\n')
			input[get_char - 1] = '\0';
		childprog = fork();
		if (childprog == -1)
		{
			perror("Error (fork)");
			exit(EXIT_FAILURE);
		}
		if (childprog == 0)
			executer(input, argv, env);
		if ((waitpid(childprog, &status, 0)) == -1)
		{
			perror("Error (waitpid)");
			exit(EXIT_FAILURE);
		}
	}
	free(input);
	return (0);
}

/**
 *executer - gives a prompt on the shell
 *@argv: input arguement
 *@path: programme path
 *@env: environment vector
 *Return: return 0
 */

void executer(const char *path, char **argv, char **env)
{
	if (execve(path, argv, env) == -1)
	{
		perror("Error (execve)");
		exit(EXIT_FAILURE);
	}
}
