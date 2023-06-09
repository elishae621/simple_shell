#include "shell.h"

/**
 * getBuiltin - check for builtin command
 * @parameters: parameter parameters
 * Return: pointer to function or 0
 */
void (*getBuiltin(char **parameters))(char **parameters)
{
	int i, j;
	funcTable Table[] = {
		{"exit", myexit},
		{"env", myenv},
		{"setenv", mysetenv},
		{"cd", cd},
		{NULL, NULL}};

	for (i = 0; Table[i].name; i++)
	{
		j = 0;
		if (Table[i].name[j] == parameters[0][j])
		{
			for (j = 0; parameters[0][j]; j++)
			{
				if (Table[i].name[j] != parameters[0][j])
					break;
			}
			if (!parameters[0][j])
				return (Table[i].func);
		}
	}
	return (0);
}
