#include "shell.h"

/**
 * setUpParameters - create memory for parameters
 * Return: pointer to array of parameters
 */
char **setUpParameters(void)
{
	char **parameters;
	int numParameters = 20, i;

	parameters = (char **)malloc(numParameters * sizeof(char *));
	if (parameters == NULL)
	{
		perror("Failed to allocate memory for parameters\n");
		exit(0);
	}
	for (i = 0; i < numParameters; i++)
	{
		parameters[i] = (char *)malloc(100 * sizeof(char));
		if (parameters[i] == NULL)
		{
			perror("Failed to allocate memory for parameters\n");
			exit(0);
		}
	}
	return (parameters);
}

/**
 * main - runs the prompt and get the command
 * Return: 0
 */
int main(void)
{
	char **parameters, *path, *pathname;
	linklist *head = NULL;
	void (*builtin)(char **);

	parameters = setUpParameters();
	while (1)
	{
		signal(SIGINT, sig_handler);
		type_prompt();
		read_command(parameters);
		path = mygetenv("PATH");
		head = linkedPath(path);
		pathname = get_command_location(parameters[0], head);
		builtin = getBuiltin(parameters);
		if (builtin)
			builtin(parameters);
		else
		{
			if (pathname)
			{
				strcpy(parameters[0], pathname);
				execute(parameters);
			}
			else
				perror("Command not found");
		}
	}
	return (0);
}
