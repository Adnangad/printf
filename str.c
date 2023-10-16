#include "main.h"

/**
 * putstr - prints string
 * @str:string to be printed
 *
 * Return:len
 */
int putstr(char *str)
{
	int j, length;

	if (str)
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			putchar(str[j]);
			length++;
		}
		return (j);
	}
	return (0);
}
