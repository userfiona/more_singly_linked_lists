#include "main.h"
#include <stdlib.h>
/**
 * _strdup - return a pointer allocated space memory.
 * @str: string
 *
 * Return: pointer of an array of chars
 */
char *_strdup(char *str);
{
	char *strout;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str [i] != '\0'; 1++);


