#include "main.h"
#include <stdio.h>

/**
 * set_bit - sets the bit of a given index to 1.
 * @n: pointer to the input number
 * @index: index of the bit to set to 1
 *
 * Return: 1 if successful, -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

		unsigned long int bit_mask = 1ul << index;
	*n |= bit_mask;
	return (1);
}
