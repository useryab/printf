#include "main.h"

/**
 * u_print - prints an unsigned integer
 * @args: list of arguments
 * Return: number of characters printed
 */
int u_print(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	count = print_unsigned_int(num);
	return (count);
}

/**
 * print_unsigned_int - prints an unsigned integer
 * @num: the number to print
 * Return: number of characters printed
 */
int print_unsigned_int(unsigned int num)
{
	int count = 0;

	char c;

	if (num / 10)
		count += print_unsigned_int(num / 10);
	c = (num % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

