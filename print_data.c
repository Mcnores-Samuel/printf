#include "main.h"
#include <stdio.h>

/**
 * print - prints data passed to it.
 * @data: the data to print to the console.
 * @buffer: buffer size or number of bytes to print.
 * Return: void/nothing.
 */
void print(char data, size_t buffer)
{
	write(1, &data, buffer);
}
