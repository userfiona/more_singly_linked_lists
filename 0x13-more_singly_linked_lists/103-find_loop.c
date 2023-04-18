#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: pointer to the head of the linked list.
 *
 * Return: the address of the node where the loop starts, or NULL if there is no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_ptr;
	listint_t *fast_ptr;
	listint_t *prev;

	slow_ptr = head;
	fast_ptr = head;
	prev = head;

	while (head && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next->next;

		if (slow_ptr == fast_ptr)
		{
			head = prev;
			prev = fast_ptr;
			while (1)
			{
				fast_ptr = prev;
				while (fast_ptr->next != head && fast_ptr->next != prev)
				{
					fast_ptr = fast_ptr->next;
				}

				if (fast_ptr->next == head)
				{
					break;
				}
				head = head->next;
				}
				return (fast_ptr->next);
			}

		prev = slow_ptr;
    }
	return (NULL);
}

