#include "binary_trees.h"
#include <limits.h>

/**
 * height - Measure the height of a binary tree.
 * @tree: Pointer to the root node of the binary tree to measure the height
 *
 * Return: The height of the binary tree - if height exists.
 *         0 - if tree is NULL
 */
size_t height(const binary_tree_t *tree)
{
    size_t left_height, right_height;

    if (!tree)
        return (0);

    left_height = height(tree->left);
    right_height = height(tree->right);
    return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * is_avl - Help to check if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * @min: Minimum allowed value for a node in the tree.
 * @max: Maximum allowed value for a node in the tree.
 *
 * Return: 1 - if the tree is a valid AVL tree.
 *         0 - otherwise.
 */
int is_avl(const binary_tree_t *tree, int min, int max)
{
    int left_height, right_height;

    if (!tree)
        return (1);

    left_height = height(tree->left);
    right_height = height(tree->right); 
    if ((tree->n < min || tree->n > max) ||
	abs(left_height - right_height) > 1)
        return (0);

    return (is_avl(tree->left, min, tree->n - 1) &&
            is_avl(tree->right, tree->n + 1, max));
}

/**
 * binary_tree_is_avl - Wrap is_avl function.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 - if the tree is a valid AVL tree.
 *         0 - otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
        	return (1);
	return (is_avl(tree, INT_MIN, INT_MAX));
}
