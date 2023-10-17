#include "main.h"
#include <stdlib.h>

void print_int(int num, int *length);
int print_bin(va_list pr);

/**
 * _printf - prints input to stdout
 * @format:the arguments
 *
 * Return:number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, num, length = 0;
	va_list pr;

	if (!format || (format[0] == '%' && format[1] == '\0') || format == NULL)
	{
		return (-1);
	}
	va_start(pr, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
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
			else if (format[i] == 'd' || format[i] == 'i')
			{
				num = va_arg(pr, int);
				print_int(num, &length);
			}
			else if (format[i] == 'b')
			{
				print_bin(pr);
			}
			else if (format[i] == '%')
			{
				putchar('%');
				length++;
			}
		}
	}
	va_end(pr);
	return (length);
}
/**
 * print_int - prints int
 * @num:int
 * @length:no of char
 *
 * Return:none.
 */
void print_int(int num, int *length)
{
	char hold[12];

	sprintf(hold, "%d", num);
	*length += putstr(hold);
}
/**
 * print_bin - converts int to binary
 * @pr:the number to be converted
 *
 * Return:none
 */
int print_bin(va_list pr)
{
	int length = 0;
	unsigned int num = va_arg(pr, unsigned int);
	int led = 1;
	int i, bit;

	for (i = 31; i >= 0; i--)
	{
		bit = (num >> i) & 1;

		if (bit)
		{
			led = 0;
		}
		if (!led)
		{
			putchar(bit + '0');
			length++;
		}
	}
	if (length == 0)
	{
		putchar('0');
		length = 1;
	}
	return (length);
}
