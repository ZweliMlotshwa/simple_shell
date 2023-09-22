#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

extern int status;

#define STATUS status

extern char **environ;

/**
 * struct built_in - Struct built_in
 *
 * @key: Variable.
 * @e: Function.
 */
typedef struct built_in
{
	char *key;
	int (*e)();
} op_t;

char *get_command(void);
char **tk_cm(char *comand, char *delim);
void free_tokens(char **token);
int _word(char *strn);
int (*get_built_in(char *s))(void);
int exit_func(void);
int env_func(void);
void check_built_in(int (*e)(), char **buffer, char *command);
char *path_d(char *comd);
void error_input(char *copy);
int execut(char **list_token, char *path);
char *get_env(void);
void freess(char *path, char **list_token);
void freesess(char *path, char **list_token, char *command);
void *_calloc(unsigned int nume, unsigned int size);

#endif /* SHELL_H */

