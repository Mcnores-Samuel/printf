#include "main.h"

/**
 * _binary - converts an integer into its binary representation.
 * @arg: argument to convert.
 * Return: total length of the binary representation as its total
 * bytes printed to the output stream.
 */
int _binary(va_list arg)
{
	int remainder;
	unsigned int binary[BUFFER_SIZE], i = 0, j, num;

	num = va_arg(arg, unsigned int);

	while (num > 0)
	{
		remainder = num % 2;
		binary[i] = remainder;
		i++;
		num = num / 2;
	}

	for (j = i - 1; j >= 0; j--)
	{
		print(binary[j], 1);
	}

	return (i);
}
