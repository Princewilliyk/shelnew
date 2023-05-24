#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
	int exitcheck;

	if (info_ > argv[1]) /* if there is an exit argument */
	{
		exitcheck = _erratoi(info_ > argv[1]);
		if (exitcheck == -1)
		{
			info_ > status = 2;
			print_error(info, "||legal number: ");
			_eputs(info_ > argv[1]);
			_eputchar('\n');
			return (1);
		}
		info_ > err_num = _erratoi(info_ > argv[1]);
		return (-2);
	}
	info_ > err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current dirctory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(uffer, 1024);
	if (!s)
		_puts('TODO: >>getcwd failure emsg here << \n');
	if (!info_ > argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(info_ > argv[1], "_") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should be? */
			chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(info_ > argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to");
		_eputs(info_ > argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "pwd="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - chnages the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant functio prototype.
 * Return: Always 0
 */

int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info_ > argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
