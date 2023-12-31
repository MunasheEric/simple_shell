#include "builtin.h"

/**
 * builtin - Check and execute the builtin
 *
 * @info: Information about the shell
 * @arguments: Commands and arguments
 *
 * Return: If the command passed is a builtin
 * return _TRUE if not return _FALSE
 **/
int builtin(general_t *info, char **arguments)
{
	int status;

	status = check_builtin(info, arguments);
	if (status == _FALSE)
		return (_FALSE);

	return (_TRUE);
}


/**
 * check_builtin - Check if the actual command is a builtin_t
 * or not
 *
 * @info: General information about the shell
 * @arguments: Arguments of the command
 *
 * Return: If the command is an actual builtin, return _TRUE
 * if not _FALSE
 **/
int check_builtin(general_t *info, char **arguments)
{
	int i, size;
	builtin_t builtin[] = {
		{"exit", bin_exit},
		{"env", bin_env}
	};

	size = sizeof(builtin) / sizeof(builtin[0]);
	for (i = 0; i < size; i++)
	{
		if (_strcmp(info->command, builtin[i].command) == 0)
		{
			builtin[i].func(info, arguments);
			return (_TRUE);
		}
	}

	return (_FALSE);
}
