#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * insert_node - insert a number into a sorted singly linked list
 * @head: pointer to the linked list
 * @number: the number that will be inserted
 *
 * Return: a pointer.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *aux;
	listint_t *new;

	if (*head == NULL || head == NULL)
		return (NULL);
	aux = *head;

	while (aux != NULL)
	{
		if (aux->next->n > number)
		{
			new = malloc(sizeof(listint_t));
			if (new == NULL)
				return (NULL);
			new->n = number;
			new->next = aux->next;
			aux->next = new;
			break;
		}
		aux = aux->next;
	}

	return (aux);
}
