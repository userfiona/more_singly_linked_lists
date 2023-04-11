#include "main.h"

/**
 * get_bit - returns the value of a bit at a given index
 * @num: number which contains the bit
 * @index: index at which bit must be found
 *
 * Return: bit (Success) or -1 (error)
 */
int get_bit(unsigned long int my_num, unsigned int my_index)
{
    int my_bit;

    // Check if index is valid
    if (my_index > (sizeof(unsigned long int) * 8 - 1))
        return (-1);

    // Extract bit at the given index
    my_bit = (my_num >> my_index) & 1;

    // Return the value of the bit
    return (my_bit);
}
