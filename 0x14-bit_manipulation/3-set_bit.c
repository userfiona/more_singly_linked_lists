#include "main.h"

/**
 * set_bit - function that sets the bit of a given index to 1.
 * @n: pointer to the input number
 * @index: the index of the bit to set to 1
 * 
 * Return: 1 if successful, -1 if failure
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	// Check if index is greater than maximum bit index (63)
	if (index > 63)
		return (-1);

	// Set mask to a 1 shifted to the index position
	unsigned long int mask = 1 << index;

	// Bitwise OR the mask and the input number to set the bit to 1
	*n = *n | mask;

	// Return 1 to indicate success
	return (1);
}
