#include "shell.h"

/**
 * own_strcpy - Copy a string from source to destination.
 * @dest: The destination buffer where the string will be copied to.
 * @src: The source string to be copied
 *
 * Thisn function copies the string 'src' tom 'dest', including the
 * null-terminator.
 * Return: pointer to destination
 */
char *own_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * own_strcat - Concatenate two strings.
 * @dest: The destination buffer where the concatenation will be stored
 * @src: The sourcestring to be concatenated to dest.
 *
 * This function appends the string 'src' to the end of the string 'dest'
 * and null-terminates the result. 'dest' must have enough space to hold
 * the concatenated string.
 *
 * Return: pointer to destination buffer
 */
char *own_strcat(char *dest, const char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * own_strdup - Duplicates a string.
 * @str: the string to duplicate.
 *
 * This function duplicates the input string 'str' and returns a pointer
 * to the duplicated string. Memory is allocated for the duplicated string,
 * so ity should be freed when no longer needed.
 *
 * Return: Pointer to the duplicated string, or NULL on failure.
 */
char *own_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_putchar - Writes the character c to standard output
 * @c: The character to print
 *
 * This function writes the character 'c' to the standard output
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * own_strspn - Get the length of a prefix substring.
 *
 * @s: Pointer to string input
 * @accept: Substring prefix to look for.
 *
 * This function calculates the length of the initial segment of 's'
 * that consists of characters present in the 'accept' string.
 * Return: the number of bytes in the initial segment.
 *
 */
unsigned int own_strspn(char *s, char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
				break;
		}
		if (!accept[j])
			return (i);
	}

	return (i);
}
