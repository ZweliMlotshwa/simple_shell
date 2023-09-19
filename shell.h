#ifndef _SHELL_H_
#define _SHELL_H_
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <sys/types.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>

/*macros*/
#define MAX_TOKENS 1024
#define PATH_SEPARATOR ":"
#define PATH_MAX_LENGTH 4096
#define BUFFER_SIZE 1024

/* prompt.c */
void prompt(void);

/* get_input.c */
char *get_input(void);
void free_last_input(void);
/* get_line.c */
void *get_line(void);

/* built-in funcs */
int own_shell_env(void);
int check_for_builtin(char **args);
int execute_buitlin(char *cmd, char **args);
int own_shell_setenv(char **args);
void own_shell_exit(char **args);
void own_shell_cd(char **args);
int own_shell_clear(char **args);
int own_shell_unsetenv(char **args);
void own_shell_help(void);

/* signal_handler.c */
void handle_sigquit(int sig);
void handle_sigint(int sig);
void handle_sigstp(int sig);

/* execute.c */
int execute(char **args);

/* parser.c */
char **tokenize(char *str, const char *delim);
char **tokenize_input(char *input);

/* get_env.c */
char *own_getenv(const char *name);

/* find_in_path.c */
char *find_in_path(char *command);

/* get_path.c */
char *get_path(void);

/* free.c */
void free_path(void);
void free_tokens(char **ptr);
void free_error(char **argv, char *arg);

/* error.c */
void own_puts(char *str);
void own_puterror(char *err);

/* utils_funcs1.c */
int own_strlen(const char *);
char *own_strstr(char *haystack, char *needle);
int own_strcmp(const char *s1, const char *s2);
char *own_strchr(char *s, char c);
int own_strncmp(const char *s1, const char *s2, size_t n);

/* utils_funcs2.c */
char *own_strdup(const char *);
char *own_strcat(char *, const char *);
char *own_strcpy(char *, char *);
int _putchar(char);
unsigned int _strspn(char *s, char *accept);

/* utils_funcs3.c */
int own_atoi(const char *str);
void *own_calloc(unsigned int nmemb, unsigned int size);
char *own_memset(char *, char, unsigned int);
char *own_memcpy(char *dest, char *src, unsigned int n);
void *own_realloc(void *, unsigned int, unsigned int);

#endif
