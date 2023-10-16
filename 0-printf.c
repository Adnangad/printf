#include "main.h"

/**
 * _printf - prints input to stdout
 * @format:the arguments
 *
 * Return:number of characters printed
 */
int _printf(const char *format, ...)
{
        int length = 0;
	va_list pr;

	if (format == NULL)
	{
		return (-1);
	}
        va_start(pr, format);
	while (*format)
        {
		if (*format != '%')
		{
			putchar(*format);
			length++;
		}
		else if(*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'c')
			{
				printc(va_arg(pr, int));
				length++;
			}
			else if (*format == 's')
			{
				length += putstr(va_arg(pr, char *));
			}
			else if(*format == '%')
			{
				putchar('%');
				length++;
			}
		}
	}
	va_end(pr);
	return (length);
}
