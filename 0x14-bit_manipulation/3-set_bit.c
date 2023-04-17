#include "main.h"

/**
 * set_bit - sets the value of a bit to 1
 * at a given index.
 * @n: pointer of an unsigned long int.
 * @index: index of the bit to be set.
 *
 * Return: 1 if it worked, -1 if it didn't.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned int mask;

	/* If the index is out of range */
	if (index > 63)
		return (-1);

	mask = 1 << index; /* Create a mask with the index set to 1 */
	*n = (*n | mask); /* Set the bit at index to 1 */

	return (1);
}
