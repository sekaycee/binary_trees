#include "binary_trees.h"

/**
 * tree_size - Measure the size of a binary tree
 * @tree: tree root
 *
 * Return: Size of the tree
 *         0 - if tree is NULL;
 */
size_t tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (tree_size(tree->left) + tree_size(tree->right) + 1);
}

/**
 * tree_is_complete - Check if tree is complete
 * @tree: pointer to the tree root
 * @i: node index
 * @cnodes: number of nodes
 *
 * Return: 1 - if tree is complete.
 *         0 - otherwise
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
 * binary_tree_is_complete - Call the tree_is_complete function
 * @tree: tree root
 *
 * Return: 1 - if tree is complete
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

/**
 * check_max - Go through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 *
 * Return: 1 - if all nodes are max.
 *         0 - in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}
	return (tmp1 && tmp2);
}
/**
 * binary_tree_is_heap - Check if a binary tree is heap
 * @tree: Pointer to the node
 * Return: 1 - in case BTS
 *         0 - otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_max(tree));
}
