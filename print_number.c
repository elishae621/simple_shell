#include "shell.h"
/**
 * helper_print_number - helper_print_number
 * @n: int n
 */
void helper_print_number(int n)
{
	int num = n;
	char tmp;

	if (num > 9)
	{

		helper_print_number(num / 10);
	}

	tmp = num % 10 + '0';
	_putchar(tmp);
}

/**
 * print_number - print_number
 * @n: int n
 */
void print_number(int n)
{
	int num = n;
	char tmp;

	if (num > 9)
		helper_print_number(num / 10);

	tmp = num % 10 + '0';
	_putchar(tmp);
}
