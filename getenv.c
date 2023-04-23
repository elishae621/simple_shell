#include "shell.h"

/**
 * _getenv - get an env from the global environ
 * @varname: variable name
 * Return: value of varname in environ
 */
char *_getenv(const char *varname)
{
	char *env_var, *env_var_name, *env_value;
	int i;

	if (varname == NULL || strlen(varname) == 0)
	{
		return (NULL); /* Invalid input */
	}

	for (i = 0; environ[i] != NULL; i++)
	{
		/* Each environment variable is in the form "VARNAME=VALUE" */
		env_var = strdup(environ[i]);
		env_var_name = strtok(env_var, "=");
		env_value = strtok(NULL, "");

		if (env_value != NULL)
		{
			if (strcmp(env_var_name, varname) == 0)
			{
				return (env_value);
			}
		}
	}

	return (NULL);
}

/**
 * env - prints out the current env
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
