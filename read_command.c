#include "shell.h"

/**
 * read_command - read command and parameters from stdin
 * @par: parameters
 */
void read_command(char *par[])
{
	char *line = NULL;
	size_t linecap = 0;
	int i = 0, j = 0, len;
	char *array[100], *pch, *delim = " ";

	/* Read one line */
	getline(&line, &linecap, stdin);

	pch = strtok(line, delim);

	/* parse the line into words */
	while (pch != NULL)
	{
		array[i++] = strdup(pch);
		pch = strtok(NULL, delim);
	}
	free(line);

	for (j = 0; j < i; j++)
	{
		len = strlen(array[j]);
		if (len > 0 && array[j][len - 1] == '\n')
		{
			array[j][len - 1] = '\0';
		}
		par[j] = array[j];
	}
	/* NULL-terminate the parameter list */
	par[i] = NULL;
}
