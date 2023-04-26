#include "shell.h"

#define BUFFER_SIZE 1024

/**
 * read_input - Reads user input from stdin and stores it in a buffer.
 * @buffer_len: The current length of the input buffer.
 * @buffer: The current length of the input buffer
 * which will be updated as characters are read into the buffer.
 *
 * Return: A pointer to the buffer containing the input, or NULL on failure.
 */

void read_input(char *buffer, size_t buffer_len)
{
	ssize_t chars_read;

	chars_read = read(STDIN_FILENO, buffer + buffer_len,
			BUFFER_SIZE - buffer_len);

	if (chars_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	if (chars_read == 0)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}

/**
 * handle_buffer - Processes the user input stored in the buffer.
 *
 * @buffer: A pointer to the buffer containing the input to be processed.
 * @buffer_len: The current length of the input buffer.
 * Return: void
 */

void handle_buffer(char *buffer, size_t *buffer_len)
{
	if (*buffer_len >= BUFFER_SIZE)
	{
		fprintf(stderr, "Error: command line too long\n");
		*buffer_len = 0;
		return;
	}
	char *newline_pos = NULL;

	while ((newline_pos = memchr(buffer, '\n', *buffer_len)) != NULL)
	{
		*newline_pos = '\0';

		char *arg = buffer;

		while (*arg != '\0')
		{
			/* skip leading whitespace */
			while (*arg == ' ' || *arg == '\t')
				arg++;
			if (*arg == '\0')

				break;

			char *end = arg;

			while (*end != ' ' && *end != '\t' && *end != '\0')

				end++;

			char old_char = *end;
			*end = '\0';
			printf("arg: %s\n", arg);
			*end = old_char;

			arg = end;
		}
		*buffer_len -= newline_pos + 1 - buffer;
		memmove(buffer, newline_pos + 1, *buffer_len);
	}
}

/**
 * main - The entry point of the program.
 *
 * Return: 0 on success, or an exit status on failure.
 */

int main(void)
{
	char buffer[BUFFER_SIZE];
	size_t buffer_len = 0;

	while (1)
	{
		printf("$ ");
		read_input(buffer, buffer_len);
		buffer_len += chars_read;
		handle_buffer(buffer, &buffer_len);
	}

	return (0);
}
