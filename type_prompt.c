#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * main - Entry point for the program
 * Description: This program implements a simple UNIX shell that
 * displays a prompt, reads a line of input from stdin, and repeats
 * the process until the user enters an EOF character (Ctrl+D).
 *
 * Return: Always 0
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	char *args[2];
	int status;

	while (1)
	{
		printf("$ ");
		if (!fgets(buffer, BUFFER_SIZE, stdin))
		{
			break;
		}
		buffer[strcspn(buffer, "\n")] = '\0';
		args[0] = buffer;
		args[1] = NULL;

		if (fork() == 0)
		{
			if (execve(args[0], args, NULL) == -1)
			{
				printf("Error: command not found\n");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}
	return (EXIT_SUCCESS);
}
