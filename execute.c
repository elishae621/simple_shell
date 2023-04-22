#include "shell.h"

/**
 * execute - executes the command with parameters
 * @parameters: array of command with parameters
 */
void execute(char **parameters)
{
	pid_t pid;
	int exev;

	pid = fork();
	if (pid == -1)
		perror(parameters[0]);

	if (pid == 0)
	{
		exev = execve(parameters[0], parameters, environ);
		if (exev == -1)
			perror("Error");
		else
			perror("Command does not exist");
	}
	wait(NULL);
}
