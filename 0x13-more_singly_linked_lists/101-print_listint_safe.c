#include "lists.h"

/**
 * print_listint_safe - prints a linked list safely
 * @head: pointer to the list
 *
 * Description: This function prints a linked list, but ensures that an infinite
 * loop is not encountered. It does so by either matching addresses or freeing
 * the head, so that it cannot loop back. It returns the number of nodes in
 * the list.
 *
 * Return: the count number of nodes
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	size_t index = 0;
	listint_t const **array; /* an array that stores everything from head */

	array = malloc(sizeof(listint_t *) * 1024); /* allocate memory for the array */
	if (!array)
		exit(98);
	unsigned int i = 0;
	unsigned int flag = 0; /* a boolean flag */

	while (head != NULL) /* loop through the list */
	{
		for (i = 0; i < count; i++) /* loop through the array */
		{
			if (head == array[i]) /* check for a match between the array values and the head */
			{
				flag = 1; /* turn the flag on */
				index = i; /* make the index equal to the i counter */
				break;
			}
			else
				flag = 0;
		}

		if (flag == 1) /* if we found a match, we break out of the loop */
			break;
		array[count]

