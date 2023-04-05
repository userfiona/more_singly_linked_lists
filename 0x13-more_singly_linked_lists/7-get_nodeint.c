#include "lists.h"

/**
 * get_nodeint_at_index -  returns the nth node of a list
 * @head: pointer to a struct
 * @index: index of a node
 *
 * Return: number of elemets
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *newnode;

	if (!head)
		return (NULL);

	newnode = head;
	while (i < index)

	{
		if (!newnode)
		return (NULL);
		newnode = newnode->next;
		i++;

	}
		return (newnode);
}
