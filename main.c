#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
	int le, le2;

	le = _printf("%c", '\0');
	le2 = printf("%c", '\0');
	fflush(stdout);
	if (le != le2)
	{
		printf("Lengths differ.\n");
        printf("in built len: %d\n", le2);
        printf("custom built len: %d\n", le);
		fflush(stdout);
		return (1);
	}
	return (0);
}