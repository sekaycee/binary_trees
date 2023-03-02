#include "binary_trees.h"
#include <limits.h>

/**
 * is_valid_bst - Check if a binary tree is a valid binary search tree.
 * @root: A pointer to the root node of the tree to check.
 * @min: The value of the smallest node visited thus far.
 * @max: The value of the largest node visited this far.
 *
 * Return: 1 - if the tree is a valid BST.
 *         0 - otherwise
 */
int is_valid_bst(const binary_tree_t *root, int min, int max)
{
	if (!root)
		return (1);

	if (root->n <= min || root->n >= max)
		return (0);

	return (is_valid_bst(root->left, min, root->n) &&
		is_valid_bst(root->right, root->n, max));
}

/**
 * binary_tree_is_bst - Wrap is_valid_bst function.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 - if tree is a valid BST.
 *         0 - otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_valid_bst(tree, INT_MIN, INT_MAX));
}
