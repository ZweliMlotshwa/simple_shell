#include "shell.h"
/**
 * _word - Function that counts the amount of words
 * that the command has according to the spaces.
 *
 * @strn: is a pointer of the incoming string
 * Return: the number of words
 */
int _word(char *strn)
{
	int count = 0;
	int word = 0;

	while (*strn)
	{
		if (*strn == ' ' || *strn == '\n' || *strn == '\t' || *strn == '='
				|| *strn == ':')
			count = 0;

		else if (count == 0)
		{
			count = 1;
			word++;
		}
		strn++;
	}
	return (word);
}

/**
 * free_tokens - Function that releases the token, 
 * iteration by iteration until reaching null.
 *
 * @token: token
 */
void free_tokens(char **token)
{
	int i = 0;

	while (token[i] != NULL)
	{
		free(token[i]);
		i++;
	}
	free(token);
}

/**
 * tk_cm - The function that splits a string based on the delimiter.
 * @comand: a pointer the command received
 * @delim: a pointer to the delimiter of the tokenize
 * Return: 0 for free, and return the result of the tokenize
 */
char **tk_cm(char *comand, char *delim)
{
	char **token = NULL;
	int i, word = 0;

	word = _word(comand);

	token = _calloc((word + 1), sizeof(char *));
	if (token == NULL)
	{
		return (NULL);
	}
	token[0] = strtok(comand, delim);
	if (token[0] == NULL)
	{
		free(token);
		return (NULL);
	}
	for (i = 1; i < word + 1; i++)
		token[i] = strtok(NULL, delim);
	return (token);
}
