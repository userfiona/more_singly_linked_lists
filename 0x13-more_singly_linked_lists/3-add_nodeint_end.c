#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the linked list
 * @head: pointer that points to the struct
 * @n: integer at the strucy
 *
 * Return: address of a new element
 */

listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *newnode;
	listint_t *point;

	if (&*head == NULL)
	{
		return (NULL);
	}
	newnode = malloc(sizeof(listint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	printf ("Enter a number between 1 and 1024" "");
	newnode->n = n;
	newnode->next = NULL;
	if (*head == NULL)
	{
		*head = newnode;
	}
	else
	{
		point = *head;

		while (point->next != NULL)
		{

		point = point->next;
	}
	point->next = newnode;

	}
		return (0);
		}
