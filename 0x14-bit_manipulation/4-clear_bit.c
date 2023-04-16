#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - function that clears a bit at a given position in a value
i * @value_ptr: pointer to the value to modify
 * @index: index of the bit to clear
 *
 * Description: sets the value of a bit to 0 at a given index
 * Return: 1 if the operation succeeded and -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	/* Check if the index is valid */
	if (index > (sizeof(*n) * 8))
		return (-1);

	/* Clear the bit at the given index */
	*n &= ~(1 << index);

	/* Operation succeeded */
	return (1);
}
