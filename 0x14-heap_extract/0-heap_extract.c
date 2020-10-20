#include "binary_trees.h"

/**
 * heap_size - get the size of heap
 * @heap: pointer to root
 * Return: size of the heap
 */
int heap_size(const heap_t *heap)
{
	size_t left, right, heap_count;

	if (!heap)
		return (0);
	left = heap_size(heap->left);
	right = heap_size(heap->right);
	heap_count = left + right + 1;

	return (heap_count);
}

/**
 * heap_search - helps to extract the root node
 * @heap: pointer to heap
 */
void heap_search(heap_t *heap)
{
	heap_t *node = heap, *child;
	int temp;

	while (1)
	{
		if (!node->left)
			break;
		if (!node->right)
			child = node->left;
		else
			child = node->left->n > node->right->n ?
				node->left : node->right;
		if (node->n > child->n)
			break;
		temp = node->n;
		node->n = child->n;
		child->n = temp;
		node = child;
	}
}

/**
 * heap_extract - extracts top node of max binary heap
 * @heap: pointer to heap
 * Return: root node
 */
int heap_extract(heap_t **heap)
{
	int n, size, bitwise;
	heap_t *node, *root;

	if (!heap || !*heap)
		return (0);

	root = *heap;
	n = root->n;
	size = heap_size(root);

	if (size == 1)
	{
		free(root);
		*heap = NULL;
		return (n);
	}

	for (bitwise = 1; bitwise <= size; bitwise <<= 1)
		;
	bitwise >>= 2;

	for (node = root; bitwise > 0; bitwise >>= 1)
		node = size & bitwise ? node->right : node->left;
	root->n = node->n;

	if (node->parent->left == node)
		node->parent->left = NULL;
	else
		node->parent->right = NULL;

	free(node);
	heap_search(root);
	*heap = root;

	return (n);
}
