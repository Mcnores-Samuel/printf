#ifndef MAIN_H
#define MAIN_H
#define BUFFER_SIZE 1024
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * operations - structure proving pointer to functions
 * @specifier: specific symbol to required to call particular
 *             function.
 * @function: The function to call for an operation after matching
 *            the specifier at the current index.
 */
typedef struct operations
{
	char specifier;
	int (*function)(va_list args);
} func_list;

void print(char data, size_t buffer);
int _printf(const char *format, ...);
int (*get_function(const char c))(va_list);
int print_char(va_list arg);
int print_string(va_list arg);
int print_percent(va_list arg);
int print_integer(va_list arg);
int print_decimal(va_list arg);
int _binary(va_list arg);
int _octal(va_list arg);
int _unsigned_int(va_list arg);

#endif
