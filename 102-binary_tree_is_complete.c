#include "binary_trees.h"

/**
 * tree_size - Count the number of nodes
 * @tree: A pointer to the tree of the binary tree
 *
 * Return: 0 - if the tree is NULl
 *         The number of nodes in the tree
 */
int tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + tree_size(tree->left) + tree_size(tree->right));
}

/**
 * binary_tree_is_complete - Check if the tree is a complete binary tree
 * @tree: A pointer to the root of the binary tree
 *
 * Return: 1 - if tree is a complete tree
 *         0 - otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t t_size, index = 0;

	if (!tree)
		return (1);

	if (index >= t_size)
		return (0);

	return (binary_tree_is_complete(tree->left, 2 * index + 1, t_size) &&
		binary_tree_is_complete(tree->right, 2 * index + 2, t_size));
}
