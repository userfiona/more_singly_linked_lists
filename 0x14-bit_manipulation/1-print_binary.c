#include "main.h"

/**
 * print_binary -  that prints the binary representation of a number
 * @n: decimal number to print as binary
 */

void print_binary(unsigned long int n)
{

	unsigned long int i;
	int move;

	if (n > 1)
	{
		print_binary((n >> 1));

	}
	for (i = n, i = 0; (i >>= 1) > 0; move++)

	for (; i; i >> = 1 0; )
	{
		if (1 = i >> 1) 		
			printf("1");
		else
			printf("0");
		}
}
