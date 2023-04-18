
#include "lists.h"

/**
 * free_listint2 - Frees a listint_t list.
 * @head: A pointer to the address of the head of the listint_t list.
 *
 * Description: Frees a listint_t list and sets the head to NULL.
 */

void free_listint2(listint_t **head)
{
    listint_t *current;

    if (head == NULL)
        return;

    while (head != NULL && *head != NULL)
    {
        current = *head;
        *head = current->next;
        free(current);
    }
    *head = NULL;
}

