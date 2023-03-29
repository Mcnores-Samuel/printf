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

	if (c == '\0')
		return (-1);

	print(c, 1);
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
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
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

/**
 * print_integer - prints an integer
 * @arguments: integer to print
 *
 * Return: number of chars and digits printed
 */

int print_integer(va_list arguments)
{
	int x[10];
	int f, d, t, y, i;

	t = va_arg(arguments, int);
	i = 0;
	d = 1000000000;
	x[0] = t / d;

	for (f = 1; f < 10; f++)
	{
		d /= 10;
		x[f] = (t / d) % 10;
	}
	if (t < 0)
	{
		print('-', 1);
		i++;

		for (f = 0; f < 10; f++)
			x[f] *= -1;
	}
	for (f = 0, y = 0; f < 10; f++)
	{
		y += x[f];

		if (y != 0 || f == 9)
		{
			print('0' + x[f], 1);
			i++;
		}
	}

	return (i);
}

/**
 * print_decimal - print a decimal
 * @arguments: decimal to print
 *
 * Return: number of characters and digits printed
 */

int print_decimal(va_list arguments)
{
	int x[10];
	int f, d, t, y, i;

	t = va_arg(arguments, int);
	i = 0;
	d = 1000000000;
	x[0] = t / d;

	for (f = 1; f < 10; f++)
	{
		d /= 10;
		x[f] = (t / d) % 10;
	}
	if (t < 0)
	{
		print('-', 1);
		i++;

		for (f = 0; f < 10; f++)
			x[f] *= -1;
	}
	for (f = 0, y = 0; f < 10; f++)
	{
		y += x[f];

		if (y != 0 || f == 9)
		{
			print('0' + x[f], 1);
			i++;
		}
	}

	return (i);
}
