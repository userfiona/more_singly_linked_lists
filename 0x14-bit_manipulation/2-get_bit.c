#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @num: number which contains the bit
 * @bit_index: index at which bit must be found
 *
 * Return: bit (Success) or -1 (error)
 */
int get_bit(unsigned long int num, unsigned int bit_index)
{
    int bit_value;

    /* If the bit_index is out of range */
    if (bit_index >= (sizeof(unsigned long int) * 8))
        return (-1);

    bit_value = (num >> bit_index) & 1; /* Get the bit value at bit_index */

    return (bit_value);
}

