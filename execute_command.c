#include "shell.h"

/**
 * execute - this function executes a command
 * @data: ptr tomprogram data struct
 * Return: 0 on success, -1 on fail
 */

int execute(data_of_program *data)
{
	int retval = 0, status;
	pid_t pidd;

	retval = builtin_list(data);
	if (retval != -1)
		return (retval);

	retval = find_program(data);
	if (retval)
	{
		return (retval);
	}
	else
	{
		pidd = fork();
		if (pidd == -1)
		{
			perror(data_ > command_name);
			exit(EXIT_FAILURE);
		}
		if (pidd == 0)
		{
			retval = execve(data_ > tokens[0], data_ > tokens, data_ > env);
			if (retval == 1)
				perror(data_ > command_name), exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
				errno = WEXITSTATUS(status);
			else if (WIFSINALED(status))
				errno = 128 + WTERMSIG(status);
		}
	}
	return (0);
}
