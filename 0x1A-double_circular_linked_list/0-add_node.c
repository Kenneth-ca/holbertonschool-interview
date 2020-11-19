#include "list.h"

/**
 * add_node_begin - add a new node to the start of the list
 * @list: pointer to start ogf the list
 * @str: string to copy into the new node
 * Return: address of the new node, NULL if fails
 */
List *add_node_begin(List **list, char *str)
{
	List *new, *aux;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->str = strdup(str);
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	aux = (*list)->prev;

	new->str = strdup(str);
	new->next = *list;
	new->prev = aux;

	aux->next = (*list)->prev = new;
	*list = new;

	return (new);
}


/**
 * add_node_end - adds a new node to the beginning of list
 * @list: pointer to the end of the list
 * @str: string to copy into the new node
 * Return: address of the new node, Null if fails
 */
List *add_node_end(List **list, char *str)
{
	List *new, *aux;

	new = malloc(sizeof(List));
	if (new == NULL)
		return (NULL);

	if (*list == NULL)
	{
		new->str = strdup(str);
		new->next = new->prev = new;
		*list = new;
		return (new);
	}

	aux = (*list)->prev;

	new->str = strdup(str);
	new->next = *list;
	(*list)->prev = new;
	new->prev = aux;
	aux->next = new;

	return (new);
}
