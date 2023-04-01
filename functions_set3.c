#include "main.h"

/**
 * _hex - prints a hexadecimal number of the int num.
 * @num: integer to print hex from.
 * Return: number of bytes printed.
 */
int _hex(int num)
{
	int hex[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 65, 66, 67, 68, 69, 70};
	int remainder, i = 0, j;
	unsigned int hex_num_array[1024];

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
 * _string - : prints the string. Non printable characters
 * (0 < ASCII value < 32 or >= 127) are printed this way:
 * \x, followed by the ASCII code value in hexadecimal
 * (upper case - always 2 characters)
 * @arg: the string to print.
 * Return: number of bytes printed.
 */
int _string(va_list arg)
{
	int i, len = 0;

	char *str = va_arg(arg, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++, len++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			if (str[i] == 10)
			{
				print('\\', 1);
				print('x', 1);
				print(0 + '0', 1);
				len += _hex(str[i]) + 3;
			}
			else if (str[i] > 10)
			{
				print('\\', 1);
				print('x', 1);
				len += _hex(str[i]) + 3;
			}
			else
			{
				print('\\', 1);
				print('x', 1);
				print(0 + '0', 1);
				len += _hex(str[i]) + 3;
			}
		}
		else
		{
			print(str[i], 1);
		}
	}
	return (len);
}
