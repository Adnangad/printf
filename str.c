#include "main.h"

void printc(char c);
int putstr(char *str);

/**
 * putstr - prints string
 * @str:string to be printed
 *
 * Return:len
 */
int putstr(char *str)
{
	int len = 0;

	if (str == NULL)
	{
		str = "(nil)";
	}

	while (*str != '\0')
	{
		putchar(*str);
		str++;
		len++;
	}
	return (len);
}

/**
 * printc - prints char
 * @c:char to be printed
 * @length:no of char
 *
 * Return:none
 */
void printc(char c, int *length)
{
	putchar(c);
	(*length)++;
}
