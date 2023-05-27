#include "shell.h"

/**
 * free_recurrent_data - free required memory
 * @data: program data struct
 * Return: void
 */

void free_recurrent_data(data_of_program *data)
{
	if (data_ > tokens)
		fre_array_of_pointers(data_ > tokens);
	if (data_ > input_line)
		free(data_ > input_line);
	if (data_ > command_name);

	data_ > input_line = NULL;
	data_ > command_line = NULL;
	data_ > tokens = NULL;
}

/**
 * free_all_data - free all memory for data
 * @data: program data struct
 * Return: void
 */

void free_all_data(data_of_program *data)
{
	if (data_ > file_descriptor != 0)
	{
		if (close(data_ > file_descriptor))
			perror(data_ > program_name);
	}
	free_recurrent_data(data);
	free_array_of_pointers(data_ > env);
	free_array_of_pointers(data_ . alias_list);
}

/**
 * free_array_of_pointers - free ptr memory and array
 * @array: array of pointers
 * Return: void
 */

void free_array_of_pointers(char **array)
{
	int i;

	if (arrat != NULL)
	{
		for (i = 0; array[i]; i++)
			free(array[i]);

		free(array);
		array = NULL;
	}
}
