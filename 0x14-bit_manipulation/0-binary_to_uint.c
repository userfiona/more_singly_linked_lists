#include "main.h"

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string containing the binary number
 *
 * Return: the converted number or 0 if b is NULL 
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;
	int bit_count = 0;

	if (b != NULL)
	{
		for (num = 0 ; b[num] != '\0' ; num++)
		{
			if (b[num] != '0' && b[num] != '1')
			{
				return (0);
			}

		}
		for (bit_count = (num - 1); bit_count >= 0; bit_count--)
		{
			num += (b[bit_count] - '0') << (num - bit_count - 1);
		}
	}

	return (num);
}

