#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is palindrome
 * @head: pointer to the singly linked list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	const listint_t *current;
	unsigned int i, j;
	int palindrome[4096];

	if (*head == NULL)
		return (1);

	current = *head;
	i = 0;
	while (current != NULL)
	{
		palindrome[i] = current->n;
		current = current->next;
		i++;
	}

	i--;
	j = 0;
	while (j <= i / 2)
	{
		if (palindrome[j] != palindrome[i - j])
			return (0);
		j++;
	}
	return (1);

}
