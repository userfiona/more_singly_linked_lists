#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - convert a binary number to an unsigned int
 * @b: char string
 * Return: converted decimal number or 0 if there is an unconvertable char
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int bit_count = 0;

	if (b != NULL)
	{
		for (num = 0 ; b[num] != '\0' ; num++)
		{
			if (b[num] != '0' && b[num] != '1')
				return (0);
		}
		for (bit_count = (num - 1); bit_count >= 0; bit_count--)
		{
			num += (b[bit_count] - '0') << (num - bit_count - 1);
		}
	}

	return (num);
}
