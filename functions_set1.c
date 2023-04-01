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

	if (str[0] == '\0')
		str = " ";

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
 * _integer - prints an integer
 * @arg: integer to print
 * Return: number of chars or digits printed
 */

int _integer(va_list arg)
{
	int num_array[10];
	int i, divisor, num, y, bytes = 0;

	num = va_arg(arg, int);
	divisor = 1000000000;
	num_array[0] = num / divisor;

	for (i = 1; i < 10; i++)
	{
		divisor /= 10;
		num_array[i] = (num / divisor) % 10;
	}
	if (num < 0)
	{
		print('-', 1);
		bytes++;

		for (i = 0; i < 10; i++)
			num_array[i] *= -1;
	}
	for (i = 0, y = 0; i < 10; i++)
	{
		y += num_array[i];

		if (y != 0 || i == 9)
		{
			print(num_array[i] + '0', 1);
			bytes++;
		}
	}

	return (bytes);
}

/**
 * _decimal - print a decimal
 * @arg: decimal to print
 * Return: number of characters and digits printed
 */

int _decimal(va_list arg)
{
	int num_array[10];
	int i, divisor, num, y, bytes = 0;

	num = va_arg(arg, int);
	divisor = 1000000000;
	num_array[0] = num / divisor;

	for (i = 1; i < 10; i++)
	{
		divisor /= 10;
		num_array[i] = (num / divisor) % 10;
	}
	if (num < 0)
	{
		print('-', 1);
		bytes++;

		for (i = 0; i < 10; i++)
			num_array[i] *= -1;
	}
	for (i = 0, y = 0; i < 10; i++)
	{
		y += num_array[i];

		if (y != 0 || i == 9)
		{
			print(num_array[i] + '0', 1);
			bytes++;
		}
	}

	return (bytes);
}
