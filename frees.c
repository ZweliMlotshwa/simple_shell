#include "shell.h"

/**
 * freess - a function that free the path and the list_token.
 *
 * @path: path.
 * @list_token: list token.
 */
void freess(char *path, char **list_token)
{
	free(path);
	free_tokens(list_token);
}

/**
 * freesess - a function that free the path, the list_token and the command.
 *
 * @path: path.
 * @list_token: list token.
 * @command: command.
 *
 */
void freesess(char *path, char **list_token, char *command)
{
	free(path);
	free(list_token);
	free(command);
}
