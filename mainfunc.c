#include "shell.h"

/**
 *main - takes an arguements from the input
 *@ac: arguement count
 *@av: arguement vector
 *@env: environment vector
 * Return: returns 0
 */

int main(int ac, char **av, char **env)
{
	if (ac == 1)
		shprompt(av, env);
	return (0);
}
