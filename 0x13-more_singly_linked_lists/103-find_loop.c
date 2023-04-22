#include "lists.h"

/**
 * find_listint_loop - Finds the loop contained in
 *                     a listint_t linked list.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: If there is no loop - NULL.
 *         Otherwise - the address of the node where the loop starts.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow, *fast;

	/* Check if list is empty or has only one node */
	if (head == NULL || head->next == NULL)
		return (NULL);

	/* Initialize slow and fast pointers */
	slow = head->next;
	fast = (head->next)->next;

	/* Traverse the list using the slow and fast pointers */
	while (fast)
	{
		/* If the pointers meet, a loop is detected */
		if (slow == fast)
		{
			/* Reset slow pointer to head and move at same pace as fast */
			slow = head;

			while (slow != fast)
			{
				slow = slow->next;
				fast = fast->next;
			}

			return (slow);
		}

		slow = slow->next;
		fast = (fast->next)->next;
	}

	return (NULL);
}

