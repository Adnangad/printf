#include "main.h"

/**
 * printc - prints char
 *
 * Return:c
 */
int printc(char c)
{
	write(1, &c, 1);
	return (1);
}
