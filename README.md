# 0x11. C - printf

Project to be done in teams of 2 people (your team: Jundi Yusuf, Yabsira Tekalegn)

## Printf

printf is a standard library function in C that stands for "print formatted." It is used to print formatted output to the console (stdout). The function takes a format string as its first argument, followed by additional arguments that provide the values to be formatted and printed. The format string specifies the layout and types of the expected values.

Here's the basic syntax of the printf function:

```c

#include <stdio.h>

int printf(const char *format, ...);
```
format: A format string that contains placeholders for values and optional formatting directives.
...: Ellipsis (three dots) represents the variable number of arguments.
Example of printf:

```c

#include <stdio.h>

int main() {
    int num = 42;
    double pi = 3.14159;
    char str[] = "Hello, World!";

    printf("Integer: %d\n", num);
    printf("Double: %f\n", pi);
    printf("String: %s\n", str);

    return 0;
}
```
This program uses printf to print an integer, a double, and a string. The placeholders %d, %f, and %s are used in the format string to indicate the types of the corresponding arguments.

Creating Your Own printf-Like Function:
Creating your own printf-like function involves using the <stdarg.h> header, which provides macros to handle variable argument lists. Here's a simplified example:

```c
#include <stdio.h>
#include <stdarg.h>

void myPrintf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%' && *(format + 1) != '\0') {
            switch (*(++format)) {
                case 'd':
                    printf("%d ", va_arg(args, int));
                    break;
                case 'f':
                    printf("%f ", va_arg(args, double));
                    break;
                case 's':
                    printf("%s ", va_arg(args, char *));
                    break;
                default:
                    putchar(*format);
            }
        } else {
            putchar(*format);
        }
        ++format;
    }

    va_end(args);
}

int main() {
    int num = 42;
    double pi = 3.14159;
    char str[] = "Hello, World!";

    myPrintf("Integer: %d\n", num);
    myPrintf("Double: %f\n", pi);
    myPrintf("String: %s\n", str);

    return 0;
}
```
This myPrintf function is a simplified version that handles only integers (%d), doubles (%f), and strings (%s). It uses va_list, va_start, and va_arg to iterate through the variable arguments and print the values accordingly. This example demonstrates the basic principles, and a complete printf-like function would require more features and error checking.

# Format Specifiers

## Integer Format Specifiers:

* %d: Decimal integer
* %u: Unsigned decimal integer
* %o: Octal integer
* %x or %X: Hexadecimal integer (lowercase or uppercase)

## Floating-Point Format Specifiers:

* %f: Decimal floating-point
* %e or %E: Scientific notation (lowercase or uppercase)
* %g or %G: Compact decimal or scientific notation (lowercase or uppercase)

## Character Format Specifiers:

* %c: Single character
* %s: String of characters

## Pointer Format Specifier:

* %p: Pointer address

## Width and Precision Specifiers:

* %*d: Width specifier for the integer field
* %.*f: Precision specifier for floating-point field

## Size Specifiers:

* %lu: Unsigned long
* %llu or %Lu: Unsigned long long
* %ld: Long
* %lld or %Ld: Long long

## Other Specifiers:

%%: Percent sign (literal %)

#### Use & Examples


------------

###### Specifiers

Specifier                |Output                        |Examples |
|----------------|-------------------------------|-----------------------------|
| `c` | Character | y |
| `d` or `i` | Signed integer | 1024, -1024 |
| `s` | String of characters | Hello Alx |
| `b` | Binary Representation of unsigned integer | 01010110 |
| `u` | Unsigned integer | 1024 |
| `o` | Unsigned octal | 432 |
| `x` | Unsigned hexadecimal integer | 3ca |
| `X` | Unsigned hexadecimal integer (uppercase) | 3CA |
| `S` | String with hex-ascii value replacing special chars | \x0A\x0A |
| `p` | Pointer address | 0x403212 |
| `r` | Reversed string of characters | dlroW olleH |
| `R` | ROT13 Translation of string | Uryyb |

