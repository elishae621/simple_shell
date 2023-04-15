#include "shell.h"

/**
 * read_command - read command
 * @cmd: command
 * @par: parameters
 */
void read_command(char cmd[], char *par[])
{
    char *line = NULL;
    size_t linecap = 0, linelen;
    int count = 0, i = 0, j = 0;
    char *array[100], *pch, *delim = " ";

    /* Read one line */
    linelen = getline(&line, &linecap, stdin);

    pch = strtok(line, delim);

    /* parse the line into words */
    while (pch != NULL)
    {
        array[i++] = strdup(pch);
        pch = strtok(NULL, delim);
    }
    free(line);

    /* first word is the command */
    strcpy(cmd, array[0]);

    /* others are parameters */
    for (int j = 0; j < i; j++)
    {
        par[j] = array[j];
    }
    /* NULL-terminate the parameter list */
    par[i] = NULL;
}