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
        int i, length;
        char car, *str;
        va_list pr;

	va_start(pr, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			length = 0;

			if (format[i] == 'c')
			{
				car = va_arg(pr, int);
				putchar(car);
				length++;
			}
			if (format[i] == 's')
			{
				str = va_arg(pr, char *);
				if (str == NULL)
				{
					return (NULL);
				}
				else
				{
					fputs(str, stdout);
					length += strlen(str);
				}
			}
			if (format[i] == '%')
			{
				putchar('%');
				length++;
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
