#include "shell.h"

/**
 * mygetenv - get an env from the global environ
 * @varname: variable name
 * Return: value of varname in environ
 */
char *mygetenv(const char *varname)
{
	char *env_var, *env_var_name, *env_value;
	int i;

	if (varname == NULL || _strlen(varname) == 0)
	{
		return (NULL); /* Invalid input */
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		/* Each environment variable is in the form "VARname=value" */
		env_var = _strdup(environ[i]);
		env_var_name = strtok(env_var, "=");
		env_value = strtok(NULL, "");

		if (env_value != NULL)
		{
			if (_strcmp(env_var_name, varname) == 0)
			{
				return (env_value);
			}
		}
	}

	return (NULL);
}

/**
 * myenv - prints out the current env
 * @parameters: argument passed that is ignored
 */
void myenv(char **parameters __attribute__((unused)))
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
}

/**
 * mysetenv - set the value of an env or replace if exit
 * @parameters: argument passed that is ignored
 */
void mysetenv(char **parameters)
{
	int envlen = 0, i, j = 0;
	char *env_string, *env_var, *env_var_name;

	if (!parameters[1] || !parameters[2])
	{
		perror(mygetenv("_"));
		return;
	}

	while (environ[envlen])
		envlen++;

	if (mygetenv(parameters[1]) != NULL)
	{
		for (i = 0; environ[i] != NULL; i++)
		{
			env_var = _strdup(environ[i]);
			env_var_name = strtok(env_var, "=");

			if (_strcmp(env_var_name, parameters[1]) == 0)
			{
				while (parameters[2][j])
				{
					environ[i][_strlen(parameters[i]) + 1 + j] = parameters[2][j];
					j++;
				}
			}
		}
	}
	else
	{
		env_string = malloc(_strlen(parameters[1]) + _strlen(parameters[2]) + 2);
		env_string = strconcat(parameters[1], "=", parameters[2]);
		environ[envlen] = env_string;
	}
}
