#include "fionas.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * @head: pointer of the struct
 * @idx: position of the node should be deleted
 *
 * Return: 1 successful , -1 fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t node* temp = head;
	while (temp->next->next!=NULL)
	{
		temp = temp->next;
		}
		temp->next = NULL;
		{
		for (int i=2; i< position; i++)
		{
		if (temp->next !=NULL)
		{
		temp = temp->next;
		}
		temp->next = temp->next->next;
	}
		return (-1);
	}
