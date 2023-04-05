#include "lists.h"

/**
 * pop_listint - deletes the head node of a list
 * @head: pointer to the struct
 *
 * Return: head node's data n
 */

int pop_listint(listint_t **head)
{
	int nodedata;
	listint_t *fr;

	if (*head == NULL)
	{
		return (0);
	}
	nodedata = (*head)->n;
	fr = (*head)->next;
	free(*head);
	*head = fr;
	return (nodedata);
}
