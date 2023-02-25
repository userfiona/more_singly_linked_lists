#include "main.h"

/**
 * print_line - function that draws a straight line in the terminal.
 *
 * @n: number of times of line.
 *
 * Return: void
 */

void print_line(int n)
{
	int j;

	for (j = 0; j < n; j++)
	{
		putchar('');
	}
	_putchar('\n');
}
