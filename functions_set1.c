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
		str = "(nil)";

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
 * @arguments: integer to print
 * Return: number of chars or digits printed
 */

int _integer(va_list arg)
{
	int num_array[BUFFER_SIZE], i;
	int bytes = 0, j;
	int num = va_arg(arg, int);

	if (num == 0)
	{
		print(num + '0', 1);
		return (1);
	}

	if (num < 0){
		print('-', 1);
		num = num * -1;
		bytes = 1;
	}

	for (i = 0; num > 0; i++)
	{
		num_array[i] = num % 10;
		num = num / 10;
		bytes += 1;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(num_array[j] + '0', 1);
	}
	return (bytes);
}

/**
 * _decimal - print a decimal
 * @arguments: decimal to print
 *
 * Return: number of characters and digits printed
 */

int _decimal(va_list arg)
{
	int num_array[BUFFER_SIZE], i;
	int bytes = 0, j;
	int num = va_arg(arg, int);

	if (num == 0)
	{
		print(num + '0', 1);
		return (1);
	}

	if (num < 0){
		print('-', 1);
		num = num * -1;
		bytes = 1;
	}

	for (i = 0; num > 0; i++)
	{
		num_array[i] = num % 10;
		num = num / 10;
		bytes += 1;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(num_array[j] + '0', 1);
	}
	return (bytes);
}
