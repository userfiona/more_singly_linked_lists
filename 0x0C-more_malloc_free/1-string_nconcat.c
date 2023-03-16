#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * string_nconcat - a function that concatenates string with n bytes
 * @s1: destination for concatenation
 * @s2: source of string
 * @n: int type for size of byte
 * Return: pointer to new memory allocated
 */

char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int s1_len = 0, s2_len = 0, i;
	char *s;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	/* While at index 0 */
	while (s1[s1_len] != '\0')
		s1_len++;
	while (s2[s2_len] != '\0')
		s2_len++;

	if (n >= s2_len)
		n = s2_len;


	s = malloc(sizeof(char) * n + s1_len + 1);
	if (s == NULL)
		return (NULL);

	for (i = 0; i < s1_len; i++)
		s[i] = s1[i];

	for (i = 0; i < n; i++)
		s[i + s1_len] = s2[i];

	s[i + s1_len] = '\0';

	return (s);
}

