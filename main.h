#ifndef HEADER_FILE
#define HEADER_FILE

/*
 * all libraries might not be needed
 * just included them just in case
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define BUFF_SIZE 1000000
/*
 * tried to add prototypes
 * is not finished
*/

int _putchar(char c);
int _printf(const char *format, ...);
int c_print(va_list args);
int print_percent(void);
int s_print(va_list arg_types);
int _print_decimal(va_list args, char *buff);
void int_to_str(int n, char *buff);

#endif
