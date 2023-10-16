#include "main.h"

/**
 * _printf - prints input to stdout
 * @format:the arguments
 *
 * Return:number of characters printed
 */
int _printf(const char *format, ...)
{
        int i, length = 0;
	va_list pr;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (-1);
	}
        va_start(pr, format);
	for (i = 0; format[i] != '\0'; i++)
        {
		if (format[i] != '%')
		{
			printc(format[i]);
			length++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				printc(va_arg(pr, int));
				length++;
			}
			else if (format[i] == 's')
			{
				length += putstr(va_arg(pr, char *));
			}
			else if(format[i] == '%')
			{
				printc('%');
				length++;
			}
		}
	}
	va_end(pr);
	return (length);
}
