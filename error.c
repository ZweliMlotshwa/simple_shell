#include "shell.h"

/**
 * error_input - Function that prints an error messages.
 *
 * @copy: Copy.
 */
void error_input(char *copy)
{
    char *msj_error = NULL;
    int length = 0;

    msj_error = _calloc((strlen(copy) + 23), sizeof(char));
    if (msj_error == NULL)
    {
        free(msj_error);
        return;
    }
    strcat(msj_error, "./hsh: ");
    strcat(msj_error, "1");
    strcat(msj_error, ": ");
    strcat(msj_error, copy);

    strcat(msj_error, ": not found\n");
    length = strlen(msj_error);
   
    if (write(2, msj_error, length) == -1)
    {
        perror("write");
    }

    STATUS = 32512;

    free(msj_error);
}
