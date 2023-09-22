#include "shell.h"
/**
 * execute - the Function that create a parent and child process (fork).
 *
 * @list_token: list token.
 * @path: Path
 *
 * Return: status.
 */
int execut(char **list_token, char *path)
{
	pid_t pidC;

	pidC = fork();

	if (pidC == -1)
	{
		perror("Creation of a child process was unsuccessful!");
		return (-1);
	}
	if (pidC == 0)
	{
		if (execve(path, list_token, environ) == -1)
			return (-1);
	}
	else
		wait(&status);
	STATUS = status;

	return (status);
}
