#include "shell.h"

/**
 * own_shell_setenv - Set the value of the environment variable.
 * @args: Arguments - name and value of an environment variable
 *
 * Return: Nothing
 */
int own_shell_setenv(char **args)
{
	char *name, *value;

	if (args[1] == NULL || args[2] == NULL)
	{
		own_puterror("Usage: setenv VARIABLE VALUE\n");
		return (-1);
	}

	name = args[1];
	value = args[2];

	if (setenv(name, value, 1) != 0)
	{
		own_puterror("setenv");
		return (-1);
	}
	return (0);
}

/**
 * own_shell_unsetenv - Unset an environment variable
 * @args: Arguments (name of an environment variable)
 *
 * Return: Nothing
 */
int own_shell_unsetenv(char **args)
{
	char *name;

	if (args[1] == NULL)
	{
		own_puterror("Usage: unsetenv VARIABLE\n");
		return (-1);
	}

	name = args[1];

	if (unsetenv(name) != 0)
	{
		own_puterror("unsetenv");
	}
	return (0);
}
