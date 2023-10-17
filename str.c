#include "main.h"

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
	return len;
}
