#include "lists.h"

/**
 * sum_listint - Calculates the sum of all the integers in a linked list.
 * @head: Pointer to the head node of the linked list.
 *
 * Return: The sum of all the integers in the linked list.
 */
int sum_listint(listint_t *head)
{
	int sum = 0

	if (!head)

		return (0);

		while (head)
	{
		sum += head->n;  /* add the value of the current node to the sum */
		head = head->next;  /* move to the next node */
		}
		return (sum);  /* return the final sum */
}
