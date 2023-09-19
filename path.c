#include "shell.h"

/**
 * get_path - Returns the value of PATH enviroment variable.
 *
 * Return: Pointer to the value of $PATH.
 */

char *get_path(void)
{
	return (own_getenv("PATH"));
}
