#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: double pointer to the head of the list
 * 
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *previous = NULL;  /* pointer to the previous node */
    listint_t *next_node = NULL; /* pointer to the next node */

    if (!head) /* check if the head is NULL */
        return (NULL);

    while (*head) /* traverse the list */
    {
        next_node = (*head)->next; /* store the next node in a temporary variable */
        (*head)->next = previous; /* change the pointer of the current node to point to the previous node */
        previous = (*head); /* update the previous node to the current node */
        (*head) = next_node; /* move to the next node */
    }
    (*head) = previous; /* update the head to point to the first node of the reversed list */
    return (*head);
}


