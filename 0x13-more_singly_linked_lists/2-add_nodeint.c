#include "lists.h"

/**
 * add_nodeint - add a new node at the beginning of a list
 * @head: pointer that points at the struch
 * @n: integer in the struct
 *
 * Return: the address of the new element
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *newnode;

	newnode = malloc(sizeof(listint_t));

	if (newnode == NULL)

	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = *head;
	*head = newnode;
	return (*head);
}
