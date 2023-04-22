#include "lists.h"
#include <stdio.h>

size_t count_unique_nodes(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * count_unique_nodes - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t count_unique_nodes(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t nodes_count = 1;

    if (head == NULL || head->next == NULL)
        return (0);

    tortoise = head->next;
    hare = (head->next)->next;

    while (hare)
    {
        if (tortoise == hare)
        {
            tortoise = head;
            while (tortoise != hare)
            {
                nodes_count++;
                tortoise = tortoise->next;
                hare = hare->next;
            }

            tortoise = tortoise->next;
            while (tortoise != hare)
            {
                nodes_count++;
                tortoise = tortoise->next;
            }

            return (nodes_count);
        }

        tortoise = tortoise->next;
        hare = (hare->next)->next;
    }

    return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes_count, index = 0;

   nodes_count = count_unique_nodes(head);

        if (nodes_count == 0)
    {
        for (; head != NULL; nodes_count++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }
    }

    else
    {
        for (index = 0; index < nodes_count; index++)
        {
            printf("[%p] %d\n", (void *)head, head->n);
            head = head->next;
        }

        printf("-> [%p] %d\n", (void *)head, head->n);
    }

    return (nodes_count);
}

