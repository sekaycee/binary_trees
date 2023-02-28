#include "binary_trees.h"

/*
 * binary_tree_is_full - Check if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 - if tree is NULL or is not full.
 *         1 - otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree)
	{
		if ((!tree->left && !tree->right) ||
			(tree->left && tree->right) &&
			binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right))
			return (1);
	}
	return (0);
}
