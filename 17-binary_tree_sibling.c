#include "binary_trees.h"

/**
 * binary_tree_sibling - Find the sibling of a
 *                       node in a binary tree.
 * @node: A pointer to the node to find the sibling of.
 *
 * Return: NULL - if node is NULL or there is no sibling - NULL.
 *         A pointer to the sibling - otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);
	if (node->parent->left != node)
		return (node->parent->left);
	return (node->parent->right);
}
