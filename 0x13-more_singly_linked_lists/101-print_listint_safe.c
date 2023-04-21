#include "lists.h"

/**
 * free_listint_safe - Frees a listint_t list safely.
 * @h: A pointer to the address of the head of the listint_t list.
 *
 * Description: This function safely frees a linked list by checking for loops
 *              and freeing only nodes that have not been previously freed.
 *
 * Return: The number of nodes freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t num_freed = 0;
	listint_t **node_ptrs;
	unsigned int i = 0;
	unsigned int is_loop = 0;

	node_ptrs = malloc(sizeof(listint_t *) * 1024);
	if (!node_ptrs)
		exit(98);
	while (*h != NULL)
	{
		for (i = 0; i < num_freed; i++)
		{
			if (*h == node_ptrs[i])
			{
				is_loop = 1;
				break;
			}
			else
				is_loop = 0;
		}
		if (is_loop == 1)
			break;
		node_ptrs[num_freed] = *h;
		*h = (*h)->next;
		num_freed++;
	}
	i = 0;
	while (i < num_freed)
	{
		free(node_ptrs[i]);
		i++;
	}
	free(node_ptrs);
	*h = NULL;
	return (num_freed);
}

