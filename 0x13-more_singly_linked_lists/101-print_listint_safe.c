#include "lists.h"

/**
 * print_listint_safe - prints a list but safely
 * @head: pointer to the head of the list
 *
 * Description: prints the elements of a linked list,
 *   but avoids printing an infinite loop if one exists
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	size_t index = 0;
	listint_t const **node_array;

	/* Allocate memory for array of pointers to nodes */
	node_array = malloc(sizeof(listint_t *) * 1024);
	if (!node_array)
		exit(98);

	unsigned int i = 0;
	unsigned int flag = 0;

	/* Traverse the linked list */
	while (head != NULL)
	{
		/* Check if the current node has already been printed */
		for (i = 0; i < count; i++)
		{
			if (head == node_array[i])
			{
				/* A loop has been found */
				flag = 1;
				index = i;
				break;
			}
			else
				flag = 0;
		}

		if (flag == 1)
			break;

		/* Add the current node to the array */
		node_array[count] = head;

		/* Move to the next node */
		head = head->next;

		/* Increment the count */
		count++;
	}

	/* Print the nodes in the linked list */
	i = 0;
	while (i < count)
	{
		printf("[%p] %d\n", (void *)node_array[i], node_array[i]->n);
		i++;
	}

	/* Print the node that caused the loop, if one was found */
	if (flag == 1)
		printf("-> [%p] %d\n", (void *)node_array[index], node_array[index]->n);

	free(node_array);

	/* Return the number of nodes in the list */
	return (count);
}

