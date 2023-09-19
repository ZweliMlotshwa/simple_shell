#include "shell.h"

/**
 * own_shell_cd - Changes the current working directory of shell
 * @args: Array of argumentS.
 *
 */
void own_shell_cd(char **args)
{
	char *dir = args[1];
	int ret;

	/* If no argument is provided, then change to HOME directory */
	if (dir == NULL)
	{
		dir = own_getenv("HOME");
		if (dir == NULL)
		{
			own_puts("cd: No HOME directory found\n");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}
