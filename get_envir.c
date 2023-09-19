#include "shell.h"

/**
 * own_getenv - Get the value of an environment variable.
 * @name: Name of the environment variable
 *
 * Return: Value of an environment variable, or NULL if it doesn't exist
 */
char *own_getenv(const char *name)
{
	char **env;
	size_t name_len = own_strlen(name);

	for (env = environ; *env != NULL; env++)
	{
		if (own_strncmp(*env, name, name_len) == 0 && (*env)[name_len] == '=')
		{
			return (&(*env)[name_len + 1]);
		}
	}

	return (NULL);
}
