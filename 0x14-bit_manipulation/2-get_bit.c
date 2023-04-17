#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number which contains the bit
 * @index: index at which bit must be found
 *
 * Return: bit (Success) or -1 (error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int bit_val;

	/* If the index is out of range */

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

		/* Shift the bit at the given index to the rightmost position and mask it */

		bit_val = (n >> index) & 1;

		/* Return the bit value */
		return (bit_val);
}
