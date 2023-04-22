#include "shell.h"

/**
 * type_prompt - prints out the prompt
 */
void type_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "#$ ", 4);
}
