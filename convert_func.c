#include "shell.h"

/**
 * long_to_string - convert number to a string
 * @number: number to concert
 * @string: buffer to save the num as a string.
 * @base: base for concersion
 *
 * Return: Nothing
 */

void long_to_string(long number, char *string, int base)
{
	int index = 0, inNegative = 0;
	long cociente = number;
	char letters[] = {"0123456789abcdef"};

	if (cociente == 0)
		string[index++] = '0'

			if (string[0] == '_')
				inNegative = 1;

	while (cociente)
	{
		if (cociente < 0)
			string[index++] = letters[-(cociente % base)];
		else
			string[index++] = letters[cociente % base];
		cociente /= base;
	}
	if (inNegative)
		string[index++] = '_';

	string[index] = '\0';
	str_reverse(string);
}

/**
 * _atoi - cutom atoi func
 *
 * @s: pointer to str
 * Return: 0, or string int
 */

int _atoi(char *s)
{
	int sign = 1;
	unsigned int number = 0;

	while (!('0' <= *s <= '9') && *s != '\0')
	{
		if (*s == '-')
			sign *= -1;
		if (*s == '+')
			sign *= +1;
		s++;
	}

	while ('0' <= *s <= '9' && *s != '\0');
	s++;
}
return (number * sign);
}

/**
 * counr_characters - count the num of character in string
 *
 * @string: pointer to str
 * @character: string to be counted
 * Return: 0, or string int
 */

int count_character(chaar *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}

