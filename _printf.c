#include "main.h"

/**
 * _printf - Parameters for printf
 * @format: list of arguments(format specifiers)
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	char buffer[BUFF_SIZE];
	int numBytesWritten = 0, len;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			numBytesWritten += handle_format(&format, &args, buffer, &len);
		}
		else
		{
			numBytesWritten += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (numBytesWritten);
}
/**
 * handle_format - function that handles format specifiers
 * @format: list of arguments(format specifiers)
 * @args: optional arguments
 * @buffer: to store the string
 * @len: length
 * Return: number of bytes printed
 */
int handle_format(const char **format, va_list *args, char *buffer, int *len)
{
	switch (**format)
	{
		case 'c': return c_print(*args);
		case 'd':
		case 'i':
			  *len = _print_decimal(*args, buffer);
			  write(1, buffer, *len);
				return (*len);
		case 's': return s_print(*args);
		case '%': return print_percent();
		case 'p': return _print_pointer(args, buffer);
		case 'x': return x_print(args);
		case 'u': return u_print(*args);
		case 'o': return o_print(*args);
		default:
			  write(1, "Invalid format specifier", 24);
				return (0);
	}
}

