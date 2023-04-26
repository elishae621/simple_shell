#include "shell.h"

/**
 * myexit - custom exit function to exit shell with or without a status
 * @parameters: parameters passed
 */
void myexit(char **parameters)
{
	int i, n;

	if (parameters[1])
	{
		n = _atoi(parameters[1]);
		if (n <= -1)
			n = 2;

		for (i = 0; parameters[i]; i++)
			free(parameters[i]);
		free(parameters);
		exit(n);
	}
	for (i = 0; parameters[i]; i++)
		free(parameters[i]);
	free(parameters);
	exit(0);
}
