#include "shell.h"

/**
 * own_puts - Prints a string to stdout stream
 * @str: string to print
 *
 * Return: Void
 */
void own_puts(char *str)
{
	size_t len;
	ssize_t num_written;

	len = own_strlen(str);
	num_written = write(STDOUT_FILENO, str, len);
	if (num_written == -1)
	{
		perror("write");
	}
}

/**
 * own_puterror - Prints an error message to stderror stream
 * @err: error message to print
 *
 * Return: Void
 */
void own_puterror(char *err)
{
	size_t len;
	ssize_t num_written;

	len = own_strlen(err);
	num_written = write(STDERR_FILENO, err, len);
	if (num_written == -1)
	{
		perror("write");
	}
}
