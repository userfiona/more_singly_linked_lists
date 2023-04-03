#include "lists.h"

/**
 * listint_len - prints all the element of linked list
 * in a linked list
 * pointer that points to the struct
 *
 * Return: number nodes
 */

size_t listint_len(const listint_t *h)
{
	size_t n_nodes = 0;

	while (h != 0)
	{
		n_nodes++;
		h = h->next;
	}
	return (n_nodes);
}
