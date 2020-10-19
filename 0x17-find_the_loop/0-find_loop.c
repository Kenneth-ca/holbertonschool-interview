#include "lists.h"

/**
 * find_listint_loop - checks if a singly linked list has a cycle in it
 * @head: pointer to head of list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *a, *b;

	if (head == NULL)
		return (0);
	a = head;
	b = head;
	while ((a != NULL) && (b != NULL) && (b->next != NULL))
	{
		a = a->next;
		b = b->next->next;
		if (a == b)
			break;
	}
	if (a != b)
		return (NULL);
	a = head;

	while (a != b)
	{
		a = a->next;
		b = b->next;
	}

	return (b);
}
