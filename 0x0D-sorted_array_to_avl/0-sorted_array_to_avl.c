#include "binary_trees.h"

/**
 * new_tree_node - tree node creator
 * @value: value to include in the node
 *
 * Return: the new node
 */
avl_t *new_tree_node(int value)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);
	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;
	return (new);
}

/**
 * recursive_to_avl - takes values from the array to avl
 * @array: sorted array that to turn into avl
 * @start: start index of the array
 * @end: end index of the array
 *
 * Return: return NULL if fails, otherwise the avl tree
 */
avl_t *recursive_to_avl(int *array, int start, int end)
{
	int mid = 0;
	avl_t *tree;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	tree = new_tree_node(array[mid]);

	tree->left = recursive_to_avl(array, start, mid - 1);
	tree->right = recursive_to_avl(array, mid + 1, end);

	if (tree->left != NULL)
		tree->left->parent = tree;
	if (tree->right != NULL)
		tree->right->parent = tree;

	return (tree);
}

/**
 * sorted_array_to_avl - takes array to create avl tree
 * @array: sorted array that to turn into avl
 * @size: size of the array
 *
 * Return: return NULL if fails, otherwise the avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int n = 0;

	if (array == NULL)
		return (NULL);
	n = size - 1;

	return (recursive_to_avl(array, 0, n));
}
