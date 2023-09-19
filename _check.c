#include "shell.h"

/**
 * check_for_builtin - checks if command is a builtin
 * @args: the arguments array
 *
 * Return: 1 if command is a builtin, 0 otherwise
 */
int check_for_builtin(char **args)
{
    if (!args[0])
        return (0);
    if (!own_strcmp(args[0], "exit"))
        own_shell_exit(args);
    else if (!own_strcmp(args[0], "env"))
        own_shell_env();
    else if (!own_strcmp(args[0], "setenv"))
        own_shell_setenv(args);
    else if (!own_strcmp(args[0], "unsetenv"))
        own_shell_unsetenv(args);
    else if (!own_strcmp(args[0], "help"))
        own_shell_help();
    else if (!own_strcmp(args[0], "cd"))
        own_shell_cd(args);
    else if (!own_strcmp(args[0], "clear"))
        own_shell_clear(args);
    else
        return (0);
    return (1);
}
