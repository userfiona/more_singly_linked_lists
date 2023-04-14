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
	int my_bit;

	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);
		my_bit = (n >> index) & 1;

		return (my_bit);
}
