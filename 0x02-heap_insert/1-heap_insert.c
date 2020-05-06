#include "binary_trees.h"

/**
 *binary_tree_height - measures the height of a binary tree
 *@tree: pointer to the tree
 *Return: the height
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;

	if (tree == NULL)
		return (0);
	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}

/**
 *binary_tree_is_perfect - checks if tree is perfect
 *@tree: pointer to the tree
 *Return: the height
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	else
		return (binary_tree_is_perfect(tree->left) &&
			 binary_tree_is_perfect(tree->right) &&
			(binary_tree_height(tree->left) == binary_tree_height(tree->right)));
}

/**
 * check_swap - check for max numbers at parent node
 *
 * @child: child node
 * Return: no return
 */
void check_swap(heap_t **child)
{
	heap_t *aux;
	int temp;

	aux = *child;
	while (aux->parent)
	{
		if (aux->parent->n < aux->n)
		{
			temp = aux->parent->n;
			aux->parent->n = aux->n;
			aux->n = temp;
			*child = aux->parent;
		}
		aux = aux->parent;
	}
}

/**
 * recursion_heap - a function that inserts nodes for Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *recursion_heap(heap_t **root, int value)
{
	heap_t *new;

	new = *root;
	if (binary_tree_is_perfect((*root)) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left != NULL)
		{
			new = recursion_heap(&((*root)->left), value);
			return (new);
		}
		else
		{
			(*root)->left = binary_tree_node(*root, value);
			new = (*root)->left;
			return (new);
		}
	}

	if ((*root)->right != NULL)
	{
		new = recursion_heap(&((*root)->right), value);
		return (new);
	}
	else
	{
		(*root)->right = binary_tree_node(*root, value);
		new = (*root)->right;
		return (new);
	}
	return (NULL);
}

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap
 * @root: a double pointer to the root node of the Heap
 * @value: value store in the node to be inserted
 *
 * Return: a pointer to the inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	new = binary_tree_node(NULL, value);
	if (new == NULL)
		return (NULL);

	new = recursion_heap(&(*root), value);

	check_swap(&new);

	return (new);
}
