#include "main.h"

/**
 * _binary - converts an integer into its binary representation.
 * @arg: argument to convert.
 * Return: total length of the binary representation as its total
 * bytes printed to the output stream.
 */
int _binary(va_list arg)
{
	int remainder, i = 0, j;
	unsigned int binary[BUFFER_SIZE], num;

	num = va_arg(arg, unsigned int);

	if (num <= 0)
		return (-1);

	while (num > 0)
	{
		remainder = num % 2;
		binary[i] = remainder;
		i++;
		num = num / 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(binary[j] + '0', 1);
	}

	return (i);
}

/**
 * _unsigned_int - prints unsigned decimal integer
 * @arg: the number to print.
 * Return: total length of the integer printed as the
 * total bytes.
 */
int _unsigned_int(va_list arg)
{
	int array[BUFFER_SIZE], i = 0, j;

	unsigned int num = va_arg(arg, unsigned int);

	while (num > 0)
	{
		array[i] = num % 10;
		num = num / 10;
		i++;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(array[j] + '0', 1);
	}

	return (i);
}

/**
 * _octal - converts an integer into its _octal representation.
 * @arg: argument to convert.
 * Return: total length of the octal representation as its total
 * bytes printed to the output stream.
 */
int _octal(va_list arg)
{
	int remainder, i = 0, j;
	unsigned int octal[1024], num;

	num = va_arg(arg, unsigned int);

	while (num > 0)
	{
		if (num < 8)
			octal[i] = num;

		remainder = num % 8;
		octal[i] = remainder;
		i++;
		num = num / 8;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(octal[j] + '0', 1);
	}
	return (i);
}
