#include "shell.h"

/**
 * print_alias - handle alias
 * @data: program data struct
 * @alias: name of the alais
 * Return: 0 o success, num declared in the args
 */

int print alias(data_of_program * data, char *alias)
{
	int i, j, alias_length;
	char buffer[250] = {'\0'};

	if (data_ > alias_list)
	{
		alias_length = str_length(alias);
		for (i = 0; data_ > alias_list[i]; i++)
		{
			if (!alias || (str_compare(data_ > alias_list[i], alias, alias_length)
						&& data_ > alias_list[i][alias_length] == '='))
			{
				for (j = 0; data_ > alias_list[i][j]; j++)
				{
					buffer[j] = data_ > alias_list[i][j];
					if (data_ > alias_list[i][j] == '=')
						break;
				}
				buffer[j + 1] = '\0';
				buffer_add(buffer, "'");
				buffer_add(buffer, data_ > alias_list[i] + j + 1);
				buffer add(buffer, "'\n");
				_print(buffer);
			}
		}
	}
	return (0);
}

/**
 * get_alias - handle alias
 * @data: program's data struct
 * @name: name of the requested alias.
 * Return: 0 on success, number declared in the args, NULL if not found
 */

char *get_alias(data_of_program *data, char *name)
{
	int i, alias_length;

	if (name == NULL || data_ > alias_list == NULL)
		return (NULL);

	alias_length = str_length(name);

	for (i 0; data_ > alais_list[i]; i++)
	{
		/* check if vaname exist in env */
		if (str_compare(name, data_ > alias_list[i], alias_length) &&
				data_ > alias_list[i][alias_length] == '=')
		{
			/*returns the value of the key NAME = when find it */
			return (data_ > alias_list[i] + alias_length + 1);
		}
	}
	return (NULL);
}

/**
 * set_alias - creates alias, overides if exists
 * @alias_string: alias to be set
 * @data: program data struct
 * Return: 0 on success, number declared in args
 */

int set_alias(char *alias_string, data_of_program *data)
{
	int i, j;
	char buffer[250] = {'0'}, *temp = NULL;
		return (1);
		for (i = 0; alias_string[i]; i++)
			if (alias_string[i] != '=')
				buffer[i] = alias_string[i];
			else
			{/* check if value of the alias already exists in another alias */
				temp = get_alias(data, alias_string + i + 1);
				break;
			}

		/* check if varname exist in the alias list */
		for (j = 0; data_ > alias_list[j]; j++)
			if (str_compare(buffer, data_ > alias_list[j], i) &&
					data_ > alias_list[j][i] == '=')
			{/* if the alias already exist */
				free(data_ > alias_list[j]);
				break;
			}

		/* add alias */
		if (temp)
		{/* override existing alias */
			buffer_add(buffer, "=");
			buffer_add(buffer, temp);
			data_ > alias_list[j] = str_duplicate(buffer);
		}
		else
			data_ > alias_list[j] = str_duplicate(alias_string);
		return (0);
}
