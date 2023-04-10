#include "main.h"

/**
 * binary_to_uint - converts a number to an unsigned int
 * @b: pointing to a string 0 and 1 chars
 * Return: converted number or 0 and b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int num;
	int count = 0;


	if (b != NULL)
	{
		for (num = 0 ; b[num] != '\0' ; num++)
		{
			if (b[num] != 48 && b[num] != 49)

			{
				return (0);
				}
			for (num = 0, num-- ; num >>= 0 ; num--)
		{
				count = count + ((b[num] - '0') << num);
				num++;

				}
				return (0);
				}
