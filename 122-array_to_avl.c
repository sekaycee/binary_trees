#include "binary_trees.h"

/**
 * array_to_avl - Build an AVL tree from an array.
 * @array: A pointer to the first element of the array.
 * @size: The number of elements in the array.
 *
 * Return: A pointer to the root node of the AVL tree - if success.
 *         NULL - on failure.
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *tree;
	size_t i;

	tree = NULL;
	for (i = 0; i < size; i++)
		avl_insert(&tree, array[i]);

	if (i == size)
		return (tree);

	return (NULL);
}
