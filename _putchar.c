#include <shell.h>

/**
 * _putchar - prints the character to standout
 * @c: character variable
 * Return: return the write funct
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
