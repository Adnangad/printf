#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <strlen.h>

/**
 * _printf - creates a function like printf
 * @format:hold the arguments
 *
 * Return:length
 */
int _printf(const char *format, ...)
{
        int i;
	int length = 0;
        char car, *str;
	char per = '%';
        va_list pr;

	va_start(pr, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				car = va_arg(pr, int);
				write(1, &car, 1);
				length++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(pr, char *);
				write(1, str, strlen(str));
				length += strlen(str);
			}
			else if (format[i] == '%')
			{
				write(1, &per, 1);
				length++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			length++;
		}
	}
	va_end(pr);
	return (length);
}
