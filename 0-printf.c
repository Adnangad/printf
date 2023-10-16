#include "main.h"

/**
 * _printf - prints input to stdout
 * @format:the arguments
 *
 * Return:number of characters printed
 */
int _printf(const char *format, ...)
{
        int i;
        char car, *str, per = '%';
	int length = 0;
        va_list pr;

	if (format == NULL)
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
		else if (format[i] == '%')
                {
                        i++;
			switch (format[i])
                        {
                                case 'c':
                                        printc(va_arg(pr, int);
                                        length++;
                                        break;
                                case 's':
                                        putstr(va_arg(pr, char *));
                                        length += strlen(str);
                                        break;
                                case '%':
                                        printc(per);
                                        length++;
					break;
			}
		}
	}
	va_end(pr);
	return (length);
}
