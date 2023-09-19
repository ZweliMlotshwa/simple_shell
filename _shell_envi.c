#include "shell.h"

/**
 * shell_env - Prints all environment variables.
 *
 * Return: void.
 */

int own_shell_env(void)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		own_puts(environ[i]);
		_putchar('\n');
	}

	return (0);
}
