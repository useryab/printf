#include "main.h"
/**
 * print_percent -this Prints a percent sign
 * Return: Number of characterss printed
 */
int print_percent(void)
{
	return (write(1, "%", 1));
}
