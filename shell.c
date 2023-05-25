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
	bool from_pipe = false;
	(void)argc;

	while (1 && !from_pipe)
	{
		if (isatty(STDIN_FILENO) == 0)
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
 *@argment: programme input
 *@env: environment vector
 *Return: return 0
 */

void executer(char *argment, char **argv, char **env)
{
	argv = _strtok(argment, " ");

	if (execve(argv[0], argv, env) == -1)
	{
		perror("Error (execve)");
		exit(EXIT_FAILURE);
	}
}


/**
 * **_strtok - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @d: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **_strtok(char *str, char *d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!_isdelim(str[i], d) && (_isdelim(str[i + 1], d) || !str[i + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (_isdelim(str[i], d))
			i++;
		k = 0;
		while (!_isdelim(str[i + k], d) && str[i + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}

/**
 * _isdelim - checks if character is a delimeter
 * @c: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int _isdelim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
