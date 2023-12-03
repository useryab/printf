#ifndef MAIN_H
#define MAIN_H

/*
 * all libraries might not be needed 
 * just included them just in case
*/

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/*
 * tried to add prototypes 
 * is not finished 
*/

int _putchar(char c);
int _printf(const char *format, ...);
int charsFormats(const char *format, va_list args);
int _percent(va_list list);
int _char(va_list list);
int _string(va_list list);
int _integer(va_list list);

#endif
