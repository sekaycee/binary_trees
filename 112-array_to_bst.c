#include "binary_trees.h"

/**
 * array_to_bst - Build a binary search tree from an array.
 * @array: A pointer to the first element of the array to be converted.
 * @size: The number of elements in @array.
 *
 * Return: A pointer to the root node of the created BST - if success
 *         NULL - on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	for (i = 0; i < size; i++)
		bst_insert(&tree, array[i]);

	if (i == size)
		return (tree);

	return (NULL);
}
