#include "main.h"

/**
 * flip_bits - returns the number of bits you would
 * need to flip to get from one number to another
 * @n: the first number.
 * @m: the second number.
 *
 * Return: the number of bits required to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int num_bits_flipped; // number of bits flipped so far

	for (num_bits_flipped = 0; n || m; n >>= 1, m >>= 1)
	{
		if ((n & 1) != (m & 1)) // if the least significant bits differ
			num_bits_flipped++; // increment the number of flipped bits
	}

	return (num_bits_flipped);
}

