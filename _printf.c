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
			switch (*++format)
			{
				case 'c':
					numBytesWritten += c_print(args);
					break;
				case 'd':
				case 'i':
					len = _print_decimal(args, buffer);
					write(1, buffer, len);
					numBytesWritten += len;
					break;
				case 's':
					numBytesWritten += s_print(args);
					break;
				case '%':
					numBytesWritten += print_percent();
					break;
				default:    /* Handle invalid format specifiers*/
					write(1, "Invalid format specifier", 24);
					break;
			}
		} else
		{
			numBytesWritten += write(1, format, 1);
		}
		 format++;
	}
	va_end(args);
	return (numBytesWritten);
}
