#include "shell.h"

/**
 * shell_help - displays help information for the built-in commands
 */
void own_shell_help(void)
{
	own_puts("\nShell Version 1.0.0\n\n");
	own_puts("Usage: ./hsh\n\n");
	own_puts("Shell built-in commands:\n\n");
	own_puts("help\t\tDisplay this help information\n\n");
	own_puts("cd [dir]\tChange the current working directory\n\n");
	own_puts("env\t\tDisplay the environment variables\n\n");
	own_puts("setenv\t\tSet an environment variable\n\n");
	own_puts("unsetenv\tUnset an environment variable\n\n");
	own_puts("exit\t\tExit the shell\n\n");
}
