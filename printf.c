#include "main.h"
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

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
	ssize_t len;
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
				write(STDOUT_FILENO, &car, 1);
				length++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(pr, char *);
				len = write(STDOUT_FILENO, str, strlen(str));
				length += len;
			}
			else if (format[i] == '%')
			{
				write(STDOUT_FILENO, &per, 1);
				length++;
			}
		}
		else
		{
			write(STDOUT_FILENO, &format[i], 1);
			length++;
		}
	}
	va_end(pr);
	return (length);
}
