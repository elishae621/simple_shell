#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * handle_command - Handles the user input command.
 * @command: The command entered by the user.
 *
 * This function receives a command string entered by the user and
 * checks if it is "exit" or "exit <status>". If it is, the function
 * exits the program with the specified status. Otherwise, it handles
 * other commands.
 */
void handle_command(char *command)
{
	int status = 0;

	if (strcmp(command, "exit") == 0)
	{
		exit(status);
	}
	else if (strncmp(command, "exit ", 5) == 0)
	{
		status = atoi(command + 5);
		exit(status);
	}
	else
	{
		/* Handle other commands */
	}
}

/**
 * read_command - Reads the user input command from stdin.
 * @buffer: Pointer to the buffer that will store the user input command.
 * @bufsize: The size of the buffer.
 *
 * This function prompts the user for input, reads the input from stdin,
 * and stores it in the buffer. If the input is an empty line or an error
 * occurs while reading, the function returns without doing anything.
 * Otherwise, it calls the handle_command function to handle the input.
 */
void read_command(char *buffer, size_t bufsize)
{
	ssize_t nread;

	printf("$ ");
	nread = getline(&buffer, &bufsize, stdin);

	if (nread == -1)
	{
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	if (*buffer == '\n')
	{
		return;
	}
	if (buffer[nread - 1] == '\n')
	{
		buffer[nread - 1] = '\0';
	}
	handle_command(buffer);
}

/**
 * main - Simple shell program.
 *
 * This program reads user input commands from stdin using the
 * read_command function and handles them using the handle_command
 * function. It continues to prompt for input until the user enters
 * an empty line or an error occurs.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	while (1)
	{
		read_command(buffer, bufsize);
	}

	return (0);
}
