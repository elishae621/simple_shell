#include "shell.h"

/**
 * main - runs the prompt and get the command
 * Return: 0
 */
int main(void)
{
	char **parameters, *path, *pathname;
	int numParameters = 20, i;
	linklist *head = NULL;

	/* Allocate memory for the array of string pointers */
	parameters = (char **)malloc(numParameters * sizeof(char *));

	/* Check if memory allocation was successful */
	if (parameters == NULL)
	{
		perror("Failed to allocate memory for parameters\n");
	}

	/* Allocate memory for each individual string in the array */
	for (i = 0; i < numParameters; i++)
	{
		parameters[i] = (char *)malloc(100 * sizeof(char));
	}

	while (1)
	{
		signal(SIGINT, sig_handler);
		type_prompt();
		read_command(parameters);

		path = _getenv("PATH");
		head = linkedPath(path);

		pathname = get_command_location(parameters[0], head);

		if (strcmp(parameters[0], "exit") == 0)
			exit(0);

		if (pathname)
		{
			strcpy(parameters[0], pathname);
			execute(parameters);
		}
		else
			perror("Command not found");
	}
	return (0);
}
