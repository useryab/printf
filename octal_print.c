#include "main.h"

/**
 * o_print - prints an octal number
 * @args: list of arguments
 * Return: number of characters printed
 */
int o_print(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = print_octal(num);
	return (count);
}

/**
 * print_octal - prints an octal number
 * @num: the number to print
 * Return: number of characters printed
 */
int print_octal(unsigned int num)
{
	int count = 0;

	char c;

	if (num / 8)
		count += print_octal(num / 8);
	c = (num % 8) + '0';
	write(1, &c, 1);
	return (count + 1);
}

