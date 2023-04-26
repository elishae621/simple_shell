#include "shell.h"

/**
 * read_command - read command and parameters from stdin
 * @par: parameters
 */
void read_command(char *par[])
{
	char *line = NULL;
	size_t linecap = 0;
	int i = 0, j = 0, len, rdlen;
	char *array[100], *pch, *delim = " ";

	rdlen = getline(&line, &linecap, stdin);

	/* check for EOF */
	if (rdlen == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 2);
		exit(0);
	}
	pch = strtok(line, delim);
	/* parse the line into words */
	while (pch != NULL)
	{
		array[i++] = _strdup(pch);
		pch = strtok(NULL, delim);
	}
	free(line);

	for (j = 0; j < i; j++)
	{
		len = _strlen(array[j]);
		if (len > 0 && array[j][len - 1] == '\n')
		{
			array[j][len - 1] = '\0';
		}
		par[j] = array[j];
	}
	/* NULL-terminate the parameter list */
	par[i] = NULL;
}
