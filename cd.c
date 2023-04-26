#include "shell.h"

/**
 * cd - change directory
 * @parameters: parameters to cd
 */
void cd(char **parameters)
{
	if (parameters[1] == NULL)
	{
		perror("cd: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(parameters[1]) != 0)
		{
			perror("cd");
		}
	}
}
