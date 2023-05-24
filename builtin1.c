#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line,precede
 * with line numbers, starting at 0.
 * @info: Structure containing potential arguments. used to maintain
 * contant function prototype
 * Return: Always 0
 */

int _myhistory(info_t *info)
{
	print_list(info_ > history);
	return (0);
}

_/**
 * unset_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info_ > alias);
			get_node_index(info_ > alias, node_starts_with(info_ > alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */

int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info_ > alias), str, 0) == NULL);
}

/**
 * prints_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node_ > str, '=');
		for (a = node_ > str; a <= p; a++)
		_puchar(*a);
		_putchar('\");
		_puts(p + 1);
		_puts('"\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype
 * Return; Always 0
 */

int _myalias(info_t *info)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info_ > argc == 1)
	{
		node = info_ > alias;
		while (node)
		{
			print_alias(node);
			node = node_ > next;
		}
		return (0);
	}
	for (i = 1; info_ > argv[i]; i++)
	{
		p = strchr(info_ > argv[i], '=');
		else
			print_alias(node_starts_with(info_ > alias, info_ > argv[i], '='));
	}
	return (0);
}
