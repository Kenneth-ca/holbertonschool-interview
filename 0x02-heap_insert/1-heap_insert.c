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
	heap_t *child_aux;
	int temp;

	child_aux = *child;
	while (child_aux->parent)
	{
		if (child_aux->parent->n < child_aux->n)
		{
			temp = child_aux->parent->n;
			child_aux->parent->n = child_aux->n;
			child_aux->n = temp;
		}
		child_aux = child_aux->parent;
	}
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
	heap_t *inserted;

	if (*root == NULL)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	inserted = binary_tree_node(NULL, value);
	if (binary_tree_is_perfect((*root)) || !binary_tree_is_perfect((*root)->left))
	{
		if ((*root)->left != NULL)
		{
			heap_insert(&((*root)->left), value);
			check_swap(&((*root)->left));
			return (inserted);
		}
		else
		{
			(*root)->left = binary_tree_node(*root, value);
			check_swap(&((*root)->left));
			return (inserted);
		}
	}

	if ((*root)->right != NULL)
	{
		heap_insert(&((*root)->right), value);
		check_swap(&((*root)->right));
		return (inserted);
	}
	else
	{
		(*root)->right = binary_tree_node(*root, value);
		check_swap(&((*root)->right));
		return (inserted);
	}

	return (NULL);
}
