#include "binary_trees.h"

/**
 * binary_tree_size - size of the tree
 * @tree: root of the treee
 * Return: size
 */
size_t binary_tree_size(heap_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size(tree->left) +
		binary_tree_size(tree->right));
}

/**
 * is_perfect - check if the binary tree is perfect
 * @num: number of nodes
 * Return: 1 if is perfect, otherwise 0
 */
int is_perfect(int num)
{
	num = num + 1;
	while (num % 2 == 0)
		num = num / 2;

	if (num == 1)
		return (1);
	else
		return (0);
}

/**
 * binary_tree_add - add a binary tree node in level order
 * @root: parent node
 * @node: node to be inserted
 * Return: pointer to the root
 */
heap_t *binary_tree_add(heap_t *root, heap_t *node)
{
	size_t right, left;

	if (root == NULL)
	{
		root = node;
		node->parent = root;
		return (node);
	}

	right = binary_tree_size(root->right);
	left = binary_tree_size(root->left);

	if (right == 0 && left == 0)
	{
		root->left = node;
		node->parent = root;
		return (root);
	}
	else if (right == 0 && left == 1)
	{
		root->right = node;
		node->parent = root;
		return (root);
	}
	else if (right == left)
		root->left = binary_tree_add(root->left, node);
	else if (right < left)
	{
		if (is_perfect(left))
			root->right = binary_tree_add(root->right, node);
		else
			root->left = binary_tree_add(root->left, node);
	}
	return (root);
}

/**
* heap_insert - inserts a value into a max binary heap.
*
* @root: pointer to the node
* @value: value to be inserted in the node
* Return: the new node
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node = NULL;
	int swap;

	new_node = binary_tree_node(NULL, value);
	if (new_node == NULL)
		return (NULL);

	if (*root == NULL)
	{
		*root = new_node;
		return (new_node);
	}

	*root = binary_tree_add(*root, new_node);

	while (new_node->parent && new_node->n > new_node->parent->n)
	{
		swap = new_node->parent->n;
		new_node->parent->n = new_node->n;
		new_node->n = swap;
		new_node = new_node->parent;
	}
	return (new_node);
}
