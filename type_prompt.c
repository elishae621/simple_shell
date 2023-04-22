#include "shell.h"

/**
 * type_prompt - prints out the prompt
 */
void type_prompt(void)
{
	/* clear the screen */
	/**
	 * static int first_time = 1;
	 * if (first_time)
	 * {
	 *	const char *CLEAR_SCREEN_ANSI = " \e[1;1H\e[2J";
	 *	write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
	 *	first_time = 0;
	 *}
	 */
	write(STDOUT_FILENO, "#", 2);
}
