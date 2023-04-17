#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @n: number which contains the bit
 * @bit_index: index at which bit must be found
 *
 * Return: bit (Success) or -1 (error)
 */
int get_bit(unsigned long int n, unsigned int index)
{
    int bit_value;

    /* If the index is out of range */
    if (index >= (sizeof(unsigned long int) * 8))
        return (-1);

    bit_value = (n >> index) & 1; /* Get the bit value at index */

    return (bit_value);
}

