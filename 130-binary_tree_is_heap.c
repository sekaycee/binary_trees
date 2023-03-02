#include "binary_trees.h"

/**
 * binary_tree_is_heap - Check if a binary tree is a valid max binary heap.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 - if the binary tree is a valid max binary heap.
 *         0 - otherwise.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->right)
		return (tree->n >= tree->left->n &&
			binary_tree_is_heap(tree->left));

	if (tree->n >= tree->left->n && tree->n >= tree->right->n)
		return (binary_tree_is_heap(tree->left) &&
			binary_tree_is_heap(tree->right));

	return (0);
}

