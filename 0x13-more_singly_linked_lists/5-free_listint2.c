#include "lists.h"

/**
 * free_listint2 - frees a list
 * @head: pointer to the srtuct
 *
 * Return: number of elements
 */

void free_listint2(listint_t **head)
{
	listint_t *fr;

			return;
	while (*head)
	{
		fr = *head;
		*head = fr->next;
		free(fr);
	}
	head = NULL;
}
