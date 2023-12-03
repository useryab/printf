#include "main.h"
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    for (const char *p = format; *p != '\0'; p++) {
        if (*p != '%') {
            putchar(*p);
            count++;
            continue;
        }

        p++;

        switch (*p) {
            case 'c': {
                char c = va_arg(args, int);
                putchar(c);
                count++;
                break;
            }
            case 's': {
                const char *s = va_arg(args, const char *);
                for (; *s; s++) {
                    putchar(*s);
                    count++;
                }
                break;
            }
            case '%': {
                putchar('%');
                count++;
                break;
            }
            default: {
                // Unsupported conversion specifier, print as is
                putchar('%');
                putchar(*p);
                count += 2;
                break;
            }
        }
    }

    va_end(args);
    return count;
}
