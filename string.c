#include "shell.h"

/**
 * _puts - print a string
 * @string: string to print
 */
void _puts(char *string)
{
    int len;

    len = strlen(string);
    write(STDOUT_FILENO, string, len);
}
