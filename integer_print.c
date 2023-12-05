#include "main.h"
#include <string.h>
/**
 * int_to_str- for printing integer
 * @n: arguments
 * @buff: buffer that is printed
 * Return:number of characters
*/
void int_to_str(int n, char *buff)
{
	int i = 0, j = 0, k, sign = n;
	char temp;

	if (n == 0)
	{
		buff[i++] = '0';
		buff[i] = '\0';
		return;
	}
	if (n < 0)
	{
		n = -n;
	}
	while (n > 0)
	{
		buff[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (sign < 0)
	{
		buff[i++] = '-';
	}
	buff[i] = '\0';
	k = i - 1;

	while (j < k)
	{
		temp = buff[j];
		buff[j] = buff[k];
		buff[k] = temp;
		j++;
		k--;
	}
}
/**
 * _print_decimal- for printing integer
 * @args: arguments
 * @buff: buffer that is printed
 * Return:number of characters
*/
int _print_decimal(va_list args, char *buff)
{
	int n = va_arg(args, int);
	int len = 0;

	int_to_str(n, buff);

	while (buff[len] != '\0')
	{
		len++;
	}

	return (len);
}
