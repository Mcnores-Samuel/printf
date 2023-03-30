#include "main.h"

/**
 * get_function - point to a function matching the specifier c.
 * @c: the specifier to matching for a specific function call.
 * Return: a pointer to a function to be invoked.
 * Description: The get_function function initializes an array of
 * func_list structures named call_fun that contains mappings between
 * format specifiers and printing functions. It then iterates through
 * this array until it finds the func_list structure whose specifier
 * field matches the input c. Once it finds the matching structure,
 * it returns a pointer to the function field of that structure,
 * which is a printing function.
 */
int (*get_function(const char c))(va_list)
{
	unsigned int i = 0;

	func_list call_fun[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_integer},
		{'b', _binary},
		{'u', _unsigned_int},
		{'o', _octal},
		{'\0', NULL}
	};

	while (call_fun[i].specifier != '\0')
	{
		if (call_fun[i].specifier == c)
		{
			return (call_fun[i].function);
		}
		i++;
	}
	return (NULL);
}
