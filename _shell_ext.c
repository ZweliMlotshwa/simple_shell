#include "shell.h"

/**
 * own_shell_exit - Exit the shell.
 * @args: Arguments.
 *
 * Return: None.
 */

void own_shell_exit(char **args)
{
	int status = 0;

	if (args[1] != NULL)
	{
		status = own_atoi(args[1]);
	}
	free_tokens(args);
	free_last_input();
	exit(status);
}
