#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <stdarg.h>

/**
 * ptr_to_str - Converts a pointer to a hexadecimal string
 * @p: The pointer
 * @buff: The buffer to write the string to
 */
void ptr_to_str(void *p, char *buff)
{
	uintptr_t ptr_val = (uintptr_t)p;
	int i = 0, j = 0, digit = 0;

	if (p == NULL)
	{
		strcpy(buff, "(nil)");
		return;
	}

	strcpy(buff, "0x");
	i += 2;

	for (j = (sizeof(ptr_val) << 3) - 4; j >= 0; j -= 4)
	{
		digit = (ptr_val >> j) & 0xf;
		buff[i++] = digit + (digit < 10 ? '0' : 'a' - 10);
	}
	buff[i] = '\0';
}

/**
 * _print_pointer - Prints a pointer
 * @args: The arguments
 * @buff: The buffer to write to
 * Return: The number of characters written
 */
int _print_pointer(va_list args, char *buff)
{
	void *p = va_arg(args, void *);
	int len = 0;

	ptr_to_str(p, buff);
	while (buff[len] != '\0')
	{
		len++;
	}
	return (len);
}

