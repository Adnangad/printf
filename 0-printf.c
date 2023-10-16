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
        char car, *str;
	char per = '%';
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
			write(1, &format[i], 1);
			length++;
		}
		else if (format[i] == '%')
                {
                        i++;
			switch (format[i])
                        {
                                case 'c':
                                        car = va_arg(pr, int);
                                        write(1, &car, 1);
                                        length++;
                                        break;
                                case 's':
                                        str = va_arg(pr, char *);
                                        write(1, str, strlen(str));
                                        length += strlen(str);
                                        break;
                                case '%':
                                        write(1, &per, 1);
                                        length++;
					break;
			}
		}
	}
	va_end(pr);
	return (length);
}
