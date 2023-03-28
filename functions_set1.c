#include "main.h"
#include <stdio.h>

/**
 * print_char - prints a character to the console.
 * @arg: a character to print.
 * Return: 1 to indicate that one character was printed.
 */
int print_char(va_list arg)
{
	char c = va_arg(arg, int);

	if (c != '\0')
	{
		print(c, 1);
	}
	return (1);
}

/**
 * print_string - prints a string to the console.
 * @arg: a string to print.
 * Return: return the total length of the string to
 * indicate number bytes.
 */
int print_string(va_list arg)
{
	char *str = va_arg(arg, char *);
	int i;

	if (str == NULL)
		str = "(nil)";

	for (i = 0; str[i]; i++)
	{
		print(str[i], 1);
	}
	return (i);
}

/**
 * print_percent - prints a percent sign to the console.
 * @arg: unused parameter.
 * Return: 1 to indicate number of bytes or character printed.
 */
int print_percent(__attribute__((unused))va_list arg)
{
	print('%', 1);
	return (1);
}
