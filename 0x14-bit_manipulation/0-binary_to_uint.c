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
		for (int i = (num - 1); i >= 0; i--)
		{
			{
				count = count + ((b[num] - '0') << i);
				i++;

				}
				return (0);
	}

