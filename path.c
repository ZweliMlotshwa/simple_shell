#include "shell.h"

/**
 * get_env - get environment
 *
 * Return: NULL.
 *
 */
char *get_env(void)
{
	int i = 0;
	char *path = NULL;

	while (environ && environ[i])
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
			path = strdup(environ[i]);
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * path_d - the function
 *
 * @comd: dsaf
 * Return: dfsa
 */
char *path_d(char *comd)
{
	char *path = NULL, **rout = NULL;
	char *comand = NULL;
	int i = 1;
	struct stat st;

	if (stat(comd, &st) == 0)
	{
		comand = strdup(comd);
		return (comand);
	}
	path = get_env();

	if (!path)
		return (NULL);
	rout = tk_cm(path, "=:");
	while (rout[i] != NULL)
	{
		comand = _calloc((strlen(rout[i]) + strlen(comd) + 2), sizeof(char));
		if (comand == NULL)
		{
			free(comand);
			return (NULL);
		}
		strcpy(comand, rout[i]);
		strcat(comand, "/");
		strcat(comand, comd);
		if (stat(comand, &st) == 0)
		{
			free(path);
			free(rout);
			return (comand);
		}
		free(comand);
		i++;
	}
	free(path);
	free(rout);
	error_input(comd);
	return (NULL);
}
