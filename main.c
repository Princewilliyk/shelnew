#include "shell.h"

/**
 *main - input to prompt
 *@ac: arguement count
 *@av: arguement vect
 *@env: environment var
 *Return: return 0
 */
int main(int ac, char **av, char **env)
{
	if (ac == 1)
		prompt(av, env);
	return (0);
}
