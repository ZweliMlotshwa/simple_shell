#include "shell.h"

/**
 * find_in_path - Looks for a command in each directory specified in the path.
 * @command: Pointer to command string to look for.
 *
 * Return: Pointer to the string containing the full path,
 *(success) if it is found,
 *  or NULL if it is not found (failure).
 *
 */
char *find_in_path(char *command)
{
	struct stat st;
	int i;
	char buf[PATH_MAX_LENGTH], *path, *ret, **dir;

	path = get_path();
	if (!path)
		return (NULL);
	dir = tokenize(path, PATH_SEPARATOR);
	if (!dir)
	{
		free(path);
		return (NULL);
	}

	for (i = 0; dir[i]; i++)
	{
		own_memset(buf, 0, PATH_MAX_LENGTH);
		own_strcpy(buf, dir[i]);
		own_strcat(buf, "/");
		own_strcat(buf, command);

		if (stat(buf, &st) == 0 && S_ISREG(st.st_mode) && (st.st_mode & S_IXUSR))
		{
			ret = malloc(sizeof(char) * (strlen(buf) + 1));
			if (!ret)
			{
				free_tokens(dir);
				free(path);
				return (NULL);
				}
				strcpy(ret, buf);
				free_tokens(dir);
				free(path);
				return (ret);
			}
		}

	free_tokens(dir);
	free(path);
	return (NULL);
}
