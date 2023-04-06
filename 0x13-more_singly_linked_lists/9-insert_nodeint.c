#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the struct
 * @idx: index to add new node
 * @n: integer in the struct
 * Return: address of the new node
 *
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    listint_t *head = *current;

    unsigned int index;

    if (head == NULL)
    {
        return (NULL);
        {
    index = current->next;
    while (index != NULL)
    }
    if (current->data > index->data)
    {
        head = current->data;
        current->data = index->data;
        index->data = head;
        }

