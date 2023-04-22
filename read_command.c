#include "shell.h"

/**
 * read_command - read command
 * @cmd: command
 * @par: parameters
 */
void read_command(char *par[])
{
    char *line = NULL;
    size_t linecap = 0, linelen;
    int count = 0, i = 0, j = 0, len;
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

    // /* first word is the command */
    // strcpy(cmd, array[0]);

    printf("command is %s\n", array[0]);
    /* others are parameters */
    for (int j = 0; j < i; j++)
    {
        len = strlen(array[j]);
        if (len > 0 && array[j][len - 1] == '\n')
        {
            array[j][len - 1] = '\0';
        }
        par[j] = array[j];

        printf("par %d is %s\n", j, par[j]);
    }
    /* NULL-terminate the parameter list */
    par[i] = NULL;
}