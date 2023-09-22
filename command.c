#include "shell.h"

/**
 * get_command -the getline of the shell
 * Return: the part of EOF return the buffer
 */
char *get_command(void)
{
	char *buffer = NULL;
	size_t size = 0;
	int lenght = 0;

	lenght = getline(&buffer, &size, stdin);
	if (lenght == EOF)
	{
		free(buffer);
		exit(WEXITSTATUS(STATUS));
	}
	return (buffer);
}
