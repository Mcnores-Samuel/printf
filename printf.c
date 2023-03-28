#include "main.h"
#include <stdio.h>

/**
 * _printf -  produces output according to a format.
 * @format: a character string.
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 * write output to stdout, the standard output stream
 */
int _printf(const char *format,...)
{
	va_list args;
	int (*fun_ptr)(va_list);
	unsigned int i = 0, bytes = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;

			if (!(format[i]))
				return (-1);

			fun_ptr = get_function(format[i]);
			if (fun_ptr)
			{
				bytes += fun_ptr(args);
			}
			else
			{
				print('%', 1);
				print(format[i], 1);
				bytes += 2;
			}
		}
		else
		{
			print(format[i], 1);
			bytes++;
		}
		i++;
	}
	va_end (args);
	return (bytes);
}

