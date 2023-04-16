#include "main.h"
#include <stdlib.h>

/**
 * clear_bit - function that clears a bit at a given position in a value
 * @value_ptr: pointer to the value to modify
 * @bit_position: position of the bit to clear
 *
 * Description: sets the value of a bit to 0 at a given index
 * Return: 1 if the operation succeeded and -1 if an error occurred
 */
int clear_bit(unsigned long int *value_ptr, unsigned int bit_position)
{
	/* Check if the bit position is valid */
	if (bit_position > (sizeof(*value_ptr) * 8))
		return (-1);

	/* Clear the bit at the given position */
	*value_ptr &= ~(1 << bit_position);

	/* Operation succeeded */
	return (1);
}
