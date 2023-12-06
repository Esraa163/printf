#include "main.h"

/**
* _puts -prints a string with newline
* @str: the string to print
*
* Return: void
*/

int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
* _putchar - writs the character c to stdout
* @c: the character to print
*
* Return: On success 1
* ON error, -1 returned, and err no is set appropriately
* as function write if there are any error return -1
*/

int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUT_FLUSH || i >= OUTPUT_BUT_SIZE)
	{
		write(1, buf, i)
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
