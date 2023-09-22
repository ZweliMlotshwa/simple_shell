#include "shell.h"

/**
 * calloc - Function that allocates the memory for an array, using malloc.
 *
 * @nume: type unsigned int.
 * @size: type unsigned int.
 * Return: 0
 */
void *_calloc(unsigned int nume, unsigned int size)
{
	char *res;
	unsigned int i = 0;

	if (nume == 0 || size == 0)
		return (NULL);

	res = malloc(nume * size);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < (nume * size); i++)
		res[i] = 0;

	return (res);

}
