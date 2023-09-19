#include "shell.h"

/**
 * own_clear - Clear the terminal screen.
 * @args: Array of arguments (unused in this function).
 *
 * Return: 1 to continue executing,
 *         or 0 to exit.
 */

int own_shell_clear(char **args)
{
    (void)args; /* Avoid "unused parameter" warning */
    own_puts("\033c"); /* Send ANSI escape code to clear the screen */
    return (1);
}
