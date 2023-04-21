#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr = head;
	listint_t *fast_ptr = head;

	/* Check if the linked list is empty */
	if (!head)
		return (NULL);

	/* Traverse the linked list until we reach the end or find a loop */
	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
		/* If we find a loop, reset slow_ptr to head and traverse the list again */
		if (fast_ptr == slow_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			/* Return the pointer to the node where the loop starts */
			return (fast_ptr);
		}
	}

	/* If no loop is found, return NULL */
	return (NULL);
}
