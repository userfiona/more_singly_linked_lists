#include "main.h"
#include <stdlib.h>
/**
 * create_array - makes an array of char.
 * @size: size of an array
 * @c: storage char
 *
 * Return: The pointer of an array of chars
 */
char *create_array(unsigned int size, char c);
{
	char *cr;
	unsigned int i; 

	if (size == 0)
		return (NULL);

	cr = malloc(sizeof(c) * size);

	if (cr == NULL)
		return (NULL)

	for (i = 0; i < size; 1++)
		cr[i] = c;

		return (cr);
}
