#include "shell.h"

/**
 * exit_funcion - exit command.
 * Return: 1.
 */
int exit_func(void)
{
	return (1);
}

/**
 * env_funcion - Function that looks for a builtin (env).
 *
 * Return: 0.
 */
int env_func(void)
{
    int i = 0;

    while (environ && environ[i])
    {
        if (write(STDOUT_FILENO, environ[i], strlen(environ[i])) == -1)
        {
            perror("write");
            return -1; 
        }
        if (write(STDOUT_FILENO, "\n", 1) == -1)
        {
            perror("write");
            return -1; 
        }
        i++;
    }
    return 0; 
}

/**
 * get_built_in - Selects the correct function,
 * set by the user.
 *
 * @s: format.
 * Return: 0
 *
 */
int (*get_built_in(char *s))(void)
{
	int i;
	op_t func[] = {
		{"env", env_func},
		{"exit", exit_func},
		{NULL, NULL}
	};

	for (i = 0; func[i].key != NULL; i++)
		if (strcmp(func[i].key, s) == 0)
			return (func[i].e);
	return (NULL);
}

/**
 * check_built_in - the Function that acts according to whether or not the
 * command exists.
 *
 * @e: Function to check.
 * @buffer: Space in memory.
 * @command: Command.
 */
void check_built_in(int (*e)(), char **buffer, char *command)
{
	if (e == exit_func)
	{
		free(command);
		free(buffer);
		exit(WEXITSTATUS(STATUS));
	}
	if (e)
	{
		if (e() == 1)
		{
			free(command);
			free(buffer);
		}
	}
}
