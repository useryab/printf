#include "main.h"
/**
 * s_print - this is to Prints a string
 * @arg_types: List a of argument
 *
 * Return: Number of characterss printed
 */
int s_print(va_list arg_types)
{
	int leng = 0;
	char *str = va_arg(arg_types, char *);

	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[leng] != '\0')
	{
		leng++;
	}
	return (write(1, str, leng));
}
