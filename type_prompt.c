#include "shell.h"

/**
 * check_interactive - checks if the shell is in interactive mode
 * @shell_info: a pointer to a struct holding information about the shell
 *
 * Return: 1 if the shell is in interactive mode, 0 otherwise
 */
int check_interactive(struct shell_info *shell_info)
{
	return (isatty(STDIN_FILENO) && shell_info->read_fd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiter: a string containing the delimiters to check against
 *
 * Return: 1 if the character is a delimiter, 0 otherwise
 */
int is_delimiter(char c, char *delimiter)
{
	while (*delimiter)
	{
		if (*delimiter++ == c)
			return (1);
	}
	return (0);
}

/**
 * is_alphabetic - checks if a character is an alphabetic character
 * @c: the character to check
 *
 * Return: 1 if the character is an alphabetic character, 0 otherwise
 */
int is_alphabetic(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value of the string, or 0 if no numbers are present
 */
int string_to_integer(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
