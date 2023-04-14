#include "main.h"

/**
 * clear_bit - sets a bit at a given index to 0
 * @number: pointer to the number to change
 * @index: index of the bit to set to 0
 *
 * Return: 1 for success, -1 for failure
 */
int clear_bit(unsigned long int *number, unsigned int index)
{
  /* Declare a variable to hold the bit mask */
  unsigned long int bit_mask;

  /* Check if the specified index is out of range (greater than 63) */
  if (index > 63) {
    /* Return -1 to indicate failure */
    return (-1);
  }

  /* Create a mask that has a single bit set to 1 at the specified index */
  bit_mask = 1UL << index;

  /* Use the bitwise NOT operator (~) to invert the bit mask, and then
     use the bitwise AND operator (&) to clear the bit at the specified index */
  *number = (~(bit_mask) & *number);

  /* Return 1 to indicate success */
  return (1);
}

