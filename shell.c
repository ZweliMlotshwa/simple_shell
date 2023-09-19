#include "shell.h"

/**
 * main - implements a simple shell
 * group project - by Enough and Zweli
 * Return: EXIT_SUCCESS.
 */

int main(void)
{
	char *input;
	char **args;
	int status;

	/* Register signal handlers */
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	signal(SIGTSTP, handle_sigstp);

	do {
		input = get_input();
		if (!input || !*input)/* EOF detected to exit the loop */
			break;

		args = tokenize_input(input);
		if (!args || !*args)
		{
			free(input);
			free_tokens(args);
			continue;
		}
		status = execute(args);
		free(input);
		free_tokens(args);

		status = 1;
	} while (status);

	return (EXIT_SUCCESS);
}
