#include "main.h"
#include <stdlib.h>

void print_int(int num, int *length);
void print_bin(int num, int *length);

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
				print_bin(va_arg(pr, unsigned int), &length);
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
 * @num:the number to be converted
 * @length:the char length
 *
 * Return:none
 */
void print_bin(int num, int *length)
{
	int start, end, i = 0;
	char temp, bin[33];

	if (num == 0)
	{
		bin[i++] = '\0';
	}
	while (num > 0)
	{
		bin[i++] = (num & 1) ? '1' : '0';
		num >>= 1;
	}
	bin[i] = '\0';
	start = 0;
	end = i - 1;

	while (start < end)
	{
		temp = bin[start];
		bin[start] = bin[end];
		bin[end] = temp;
		start++;
		end--;
	}
	*length += putstr(bin);
}
