#include "binary_trees.h"

/**
 * create_tree - Help create an AVL tree recursively
 * @node: A pointer node
 * @array: input array of integers
 * @size: size of array
 * @mode: 1 to adding on the left, 2 to adding on the right
 */
void create_tree(avl_t **node, int *array, size_t size, int mode)
{
	size_t center;

	if (size == 0)
		return;

	center = (size / 2);
	center = (size % 2 == 0) ? center - 1 : center;
	if (mode == 1)
	{
		(*node)->left = binary_tree_node(*node, array[center]);
		create_tree(&((*node)->left), array, center, 1);
		create_tree(&((*node)->left), array + center + 1,
			(size - 1 - center), 2);
	}
	else
	{
		(*node)->right = binary_tree_node(*node, array[center]);
		create_tree(&((*node)->right), array, center, 1);
		create_tree(&((*node)->right), array + center + 1,
			(size - 1 - center), 2);
	}
}

/**
 * sorted_array_to_avl - Create root node using create_tree function.
 * @array: An array of integers.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root - if success.
 *         NULL - on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root;
	size_t center;

	root = NULL;
	if (size == 0)
		return (NULL);

	center = (size / 2);
	center = (size % 2 == 0) ? center - 1 : center;
	root = binary_tree_node(root, array[center]);

	create_tree(&root, array, center, 1);
	create_tree(&root, array + center + 1, (size - 1 - center), 2);

	return (root);
}
