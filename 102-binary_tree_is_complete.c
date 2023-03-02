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
 * tree_is_complete - checks if tree is complete
 *
 * @tree: pointer to the tree root
 * @i: node index
 * @cnodes: number of nodes
 * Return: 1 if tree is complete, 0 otherwise
 */
int tree_is_complete(const binary_tree_t *tree, int i, int cnodes)
{
	if (!tree)
		return (1);

	if (i >= cnodes)
		return (0);

	return (tree_is_complete(tree->left, (2 * i) + 1, cnodes) &&
		tree_is_complete(tree->right, (2 * i) + 2, cnodes));
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
	size_t cnodes;

	if (!tree)
		return (0);

	cnodes = tree_size(tree);
	return (tree_is_complete(tree, 0, cnodes));
}
