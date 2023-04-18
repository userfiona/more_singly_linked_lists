/*
 * File: 5-free_listint2.c
 * Auth: Gedeon Obae Gekonge
 */

#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 *
 * Description: Frees a listint_t list and sets the head to NULL.
 */
void free_listint2(listint_t **head)
{
	listint_t *temp;

	if (head == NULL)
		return;

		while (*head != NULL)
	{
		temp = (*head)->next;
		free(*head);
		*head = temp;
	}

	*head = NULL;
}

