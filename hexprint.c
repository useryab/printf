#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


/**
 * x_print - function that handles %x format specifier
 * @args: optional arguments
 * Return: number of bytes printed
 */
int x_print(va_list *args)
{
	unsigned int num = va_arg(*args, unsigned int);
	char buffer[20], temp;
	int i = 0, len;
	unsigned int tempo = 0;
    /* Convert to hexadecimal*/
	do {
		tempo = num % 16;
		if (tempo < 10)
			buffer[i] = tempo + 48;
		else
			buffer[i] = tempo + 87;
		num = num / 16;
		i++;
	} while (num != 0);

	/* Reverse the string*/
	len = i;
	for (i = 0; i < len / 2; i++)
	{
		temp = buffer[i];
		buffer[i] = buffer[len - i - 1];
		buffer[len - i - 1] = temp;
	}

	/* Write to stdout*/
	buffer[len] = '\0';
	write(1, buffer, len);
	return (len);
}

