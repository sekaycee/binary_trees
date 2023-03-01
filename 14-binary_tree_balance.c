#include "binary_trees.h"

/**
 * binary_tree_height - Measure the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: 0 - if tree is NULL.
 *         Tree height - otherwise
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t hl = 0, hr = 0;

		hl = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		hr = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return (hl > hr ? hl : hr);
	}
	return (0);
}

/**
 * binary_tree_balance - Measure the balance factor of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the balance factor.
 *
 * Return: 0 - if tree is NULL.
 *         Balance factor - otherwise
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int b_factor = 0;

	if (tree)
	{
		b_factor += binary_tree_height(tree->left);
		b_factor -= binary_tree_height(tree->right);
		return (b_factor);
	}
	return (0);
}
