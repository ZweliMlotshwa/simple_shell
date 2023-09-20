#include "shell.h"

/**
 * get_input - Read the line of input from user.
 *
 * Return: Pointer to a buffer conatining the user's input.
*/

int main(void)
{
    char *input;
    char **args;
    int status = 0;

    do {
        input = get_input();

        if (input == NULL) {
            own_puts("\n");
            break;
        }

        args = tokenize_input(input);

        if (args == NULL || args[0] == NULL) {
            free(input);
            continue;
        }

        status = execute(args);

        free(input);
        free_tokens(args);

    } while (1);

    (void)status;

    return EXIT_SUCCESS;
}
