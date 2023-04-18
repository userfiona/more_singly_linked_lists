#include "lists.h"

/**
 * print_listint_safe - Prints a linked list of integers but safely
 * @head: Pointer to the head node of the list
 *
 * Description: The function prints the values and addresses of each node in
 * the list in the order that they appear. It ensures that no infinite loop is
 * created while printing the list. The function also returns the number of
 * nodes in the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	size_t index = 0;
	listint_t const **array;

	array = malloc(sizeof(listint_t *) * 1024); // Allocate memory for array
	if (!array)
		exit(98); // Handle memory allocation error

	unsigned int i = 0;
	unsigned int flag = 0;

	while (head != NULL) // Iterate through the list
	{
		for (i = 0; i < count; i++)
		{
			if (head == array[i]) // Check if the node already exists in the array
			{
				flag = 1;
				index = i;
				break;
			}
			else
				flag = 0;
		}

		if (flag == 1) // If a loop is found, break out of the loop
			break;

		array[count] = head; // Add the current node to the array
		head = head->next;
		count++;
	}

	i = 0;
	while (i < count) // Print the nodes in the list
	{
		printf("[%p] %d\n", (void *)array[i], array[i]->n);
		i++;
	}

	if (flag == 1) // If a loop is found, print the node that causes the loop
	{
		printf("-> [%p] %d\n", (void *)array[index], array[index]->n);
	}

	free(array); // Free the memory allocated for the array
	return (count);
}

