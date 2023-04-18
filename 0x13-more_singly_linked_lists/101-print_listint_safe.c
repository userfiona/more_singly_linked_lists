#include "lists.h"

/**
 * print_listint_safe - prints a linked list of integers, but safely
 * @head: pointer to the head node
 *
 * Description: This function prints a linked list of integers. It keeps
 * track of the memory addresses of the nodes it has already printed, so
 * that it does not enter an infinite loop if the list contains a cycle.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;        /* number of nodes in the list */
	size_t index = 0;        /* index of the node where a cycle was detected */
	listint_t const **array;/* an array to keep track of the nodes */

	array = malloc(sizeof(listint_t *) * 1024);/* allocate memory for the array */
	if (!array)
		exit(98);           /* exit if allocation fails */
	unsigned int i = 0;     /* loop counter */
	unsigned int flag = 0;  /* flag to indicate if a cycle was detected */

	while (head != NULL)     /* iterate through the list */
	{
		for (i = 0; i < count; i++)/* loop through the array */
		{
			if (head == array[i])/* check if the node is already in the array */
			{
				flag = 1;       /* set the flag */
				index = i;      /* save the index */
				break;          /* break out of the loop */
			}
			else
				flag = 0;
		}

		if (flag == 1)  /* if a cycle was detected, break out of the loop */
			break;
		array[count] = head;    /* add the node to the array */
		head = head->next;      /* move to the next node */
		count++;                /* increment the count */
	}

	i = 0;
	while (i < count)           /* loop through the array again */
	{
		printf("[%p] %d\n", (void *)array[i], array[i]->n);
		i++;
	}
	if (flag == 1)              /* if a cycle was detected, print the node where it occurs */
	{
		printf("-> [%p] %d\n", (void *)array[index], array[index]->n);
	}
	free(array);                /* free the array */
	return (count);             /* return the count */
}

