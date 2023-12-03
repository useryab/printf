#include"main.h"
#include <stdio.h>
#include <stdarg.h>

/*
 *
 *
 */ 

void myPrintf(const char *format, ...)
// make sure you use approprite prototype and change lib
{
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i')) {
            int value = va_arg(args, int);
            printf("%d", value);
            format += 2; // Skip '%' and 'd' or 'i'
        } else {
            putchar(*format);
            ++format;
        }
    }

    va_end(args);
}

int main() {
    int num = 42;

    myPrintf("This is a number: %d\n", num);
    myPrintf("This is also a number: %i\n", num);

    return 0;
}

