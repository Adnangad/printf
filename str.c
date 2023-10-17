#include "main.h"

void printc(char c, int *length);
int putstr(char *str, int *length);

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
 *
 * Return:none
 */
void printc(char c)
{
	putchar(c);
}
