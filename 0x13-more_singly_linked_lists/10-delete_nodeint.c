#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes the node at a given
 *                           index of a listint_t list.
 * @head: A pointer to the address of the
 *        head of the listint_t list.
 * @index: The index of the node to be deleted - indices start at 0.
 *
 * Return: On success - 1.
 *         On failure - -1.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp, *current_node = *head;
	unsigned int current_index;

	if (current_node == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(current_node);
		return (1);
	}

	for (current_index = 0; current_index < (index - 1); current_index++)
	{
		if (current_node->next == NULL)
			return (-1);

		current_node = current_node->next;
	}

	temp = current_node->next;
	current_node->next = temp->next;
	free(temp);
	return (1);
}

