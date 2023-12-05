#include "main.h"

/**
 * c_print - Prints a characters
 * @args: List of arguments
 *
 *
 * Return: Number of characterss printed
 */
int c_print(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (0);
}

