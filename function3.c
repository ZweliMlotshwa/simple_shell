#include "shell.h"

/**
 * own_atoi - Converts a string to an integer.
 * @str: String to convert.
 *
 * Return: The integer value of the string.
 */
int own_atoi(const char *str)
{
	int i, sign;
	unsigned int num;

	i = 0;
	sign = 1;
	num = 0;

	while (str[i] != '\0')
	{
		if (str[i] == '-')
			sign *= -1;
		else if (str[i] >= '0' && str[i] <= '9')
			num = (num * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	return (num * sign);
}

/**
 **own_memset - Fills memory with a constant byte.
 *@s: The pointer to the memory area.
 *@b: The byte to fill *s with.
 *@n: The amount of bytes to be filled.
 *Return: a pointer to the memory area s
 */
char *own_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * own_memcpy - Function that copies memory area.
 *
 * @dest: Buffer where we will copy to.
 * @src: What we are to copy.
 * @n: n bytes of @src.
 *
 * Return: Always 0 (Success)
*/

char *own_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		dest[i] = src[i];
	return (dest);
}

/**
 * own_realloc - Reallocates a block of memory.
 * @ptr: Pointer to previous mallocated block.
 * @old_size: byte size of previous block.
 * @new_size: byte size of new block.
 *
 * Return: pointer to the old block namen.
 */
void *own_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

/**
 * own_calloc - a function that allocates
 * memory for an array using malloc
 *
 * It is basically the equivalent to
 * malloc followed by memset
 * @nmemb: the size of array
 * @size: the size of each element
 *
 * Return: pointer with new allocated memory
 *         or NULL if it fails
*/

void *own_calloc(unsigned int nmemb, unsigned int size)
{
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	p = malloc(nmemb * size);
	if (p == NULL)
		return (NULL);

	own_memset(p, 0, nmemb * size);

	return (p);
}
