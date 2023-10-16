#include "main.h"

/**
 * _printf - creates a function like printf
 * @format:hold the arguments
 *
 * Return:length
 */
int _printf(const char *format, ...)
{
        int length = 0;
        char car, *str;
	char per = '%';
        va_list pr;

	va_start(pr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			if (*format == 'c')
			{
				car = va_arg(pr, int);
				write(1, &car, 1);
				length++;
			}
			else if (*format == 's')
			{
				str = va_arg(pr, char *);
				write(1, str, strlen(str));
				length += strlen(str);
			}
			else if (*format == '%')
			{
				write(1, &per, 1);
				length++;
			}
		}
		else
		{
			write(1, format, 1);
			length++;
		}
		format++;
	}
	va_end(pr);
	return (length);
}
