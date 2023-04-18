#include "lists.h"

/**
 * sum_listint - sum of all data linked
 * @head: pointer to the struct
 *
 * Return: number of elements
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

    if (!head)

		return (0);

    while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
