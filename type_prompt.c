#include "shell.h"
#include <errno.h>

#define BUFFER_SIZE 1024


/**
 * type_prompt - Prints out a prompt to stdout
 * Description: This function checks if the stdin file descriptor is
 * associated with a terminal and prints a prompt accordingly. If the
 * file descriptor is not a terminal, no prompt is printed.
 *
 * Return: void
*/

void type_prompt(void)
{
	if (isatty(STDIN_FILENO))
	write(STDOUT_FILENO, "#$ ", 3);
}

/**
 * read_input - Reads a line from stdin and stores it in a buffer
 * @buffer: The buffer to store the line read from stdin
 * @buffer_len: The maximum length of the buffer
 *
 * Description: This function reads a line from stdin and stores it in
 * the buffer. The maximum length of the buffer is specified by the
 * buffer_len argument. If the input line is longer than the buffer,
 * only the first buffer_len characters will be stored in the buffer.
 * Return: The number of characters read from stdin, or -1 on failure
 */

char *read_input(char *buffer, size_t buffer_len)
{
	if (fgets(buffer, buffer_len, stdin) == NULL)
		return (NULL);

	size_t len = strlen(buffer);

	if (len > 0 && buffer[len - 1] == '\n')
		buffer[len - 1] = '\0';
	return (buffer);
}

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

	while (1)
	{
		type_prompt();

		if (read_input(buffer, BUFFER_SIZE) == NULL)
		{
			printf("\n");
			break;
		}
		pid_t pid = fork();

		if (pid < 0)
		{
			perror("fork");
			continue;
		}
		if (pid == 0)
		{
			char *args[] = { buffer, NULL };

			execve(buffer, args, NULL);
			perror("execve");
			exit(EXIT_FAILURE);
		}
		else
		{
			waitpid(pid, NULL, 0);
		}
	}
	return (EXIT_SUCCESS);
}
