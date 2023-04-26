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
 * printCustomError - print customs error for command not found
 * @shell: current shell
 * @line_number: line number
 * @parameter: command passed to shell
 */
void printCustomError(char *shell, int line_number, char *parameter)
{
	_puts(shell);
	_puts(": ");
	print_number(line_number);
	_puts(": ");
	_puts(parameter);
	_puts(": not found\n");
}

/**
 * main - runs the prompt and get the command
 * @argc: number of parameters passed
 * @argv: array of parameters passed
 * Return: 0
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char **parameters, *path, *pathname;
	linklist *head = NULL;
	void (*builtin)(char **);
	char *shell;
	int line_number = 0;

	shell = *argv;
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
			++line_number;
			if (pathname)
			{
				_strcpy(parameters[0], pathname);
				execute(parameters);
			}
			else
				printCustomError(shell, line_number, parameters[0]);
		}
	}
	return (0);
}
