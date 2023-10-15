#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/**
 * _printf - creates a function like printf
 * @format:hold the arguments
 *
 * Return:length
 */
int _printf(const char *format, ...)
{
        int i;
        char car, *str;
	int length = 0;
        va_list pr;

        va_start(pr, format);
        for (i = 0; format[i]; i++)
        {
                if (format[i] == '%')
                {
                        i++;
                        switch (format[i])
                        {
                                case 'c':
                                        car = va_arg(pr, int);
                                        putchar(car);
                                        length++;
                                        break;
                                case 's':
                                        str = va_arg(pr, char *);
                                        fputs(str, stdout);
                                        length += strlen(str);
                                        break;
                                case '%':
                                        putchar('%');
                                        length++;
					break;
				default:
					length++;
					break;
			}
		}
		else
		{
			putchar(format[i]);
			length++;
		}
	}
	va_end(pr);
	return (length);
}
