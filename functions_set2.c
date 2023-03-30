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
	unsigned int octal[BUFFER_SIZE], num;

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

/**
 * lowercase_hex - converts integer to hexadecimal numbers and
 * the letter in hexadecimal number are lowercase letter.
 * @arg: the integer to converts.
 * Return: total length of the output as the character bytes
 */
int lowercase_hex(va_list arg)
{
	int hex[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 97, 98, 99, 100, 101, 102};
	int remainder, i = 0, j;
	unsigned int hex_num_array[BUFFER_SIZE], num;

	num = va_arg(arg, unsigned int);

	while (num > 0)
	{
		remainder = num % 16;
		hex_num_array[i] = hex[remainder];
		i++;
		num = num / 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (hex_num_array[j] <= 9)
		{
			print(hex_num_array[j] + '0', 1);
		}
		else
		{
			print(hex_num_array[j], 1);
		}
	}
	return (i);
}

/**
 * uppercase_hex - converts integer to hexadecimal numbers and
 * the letter in hexadecimal are uppercase letter
 * @arg: the integer to converts.
 * Return: total length of the output as the character bytes
 */
int uppercase_hex(va_list arg)
{
	int hex[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 65, 66, 67, 68, 69, 70};
	int remainder, i = 0, j;
	unsigned int hex_num_array[BUFFER_SIZE], num;

	num = va_arg(arg, unsigned int);

	while (num > 0)
	{
		remainder = num % 16;
		hex_num_array[i] = hex[remainder];
		i++;
		num = num / 16;
	}

	for (j = i - 1; j >= 0; j--)
	{
		if (hex_num_array[j] <= 9)
		{
			print(hex_num_array[j] + '0', 1);
		}
		else
		{
			print(hex_num_array[j], 1);
		}
	}
	return (i);
}
