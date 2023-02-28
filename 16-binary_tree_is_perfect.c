#include "binary_trees.h"

/*
 * is_perfect - Check if the tree is perfect.
 * @tree: A pointer to the root node of the tree to check.
 * @leaf_depth: The depth of one leaf in the binary tree.
 * @level: Level of current node.
 *
 * Return: 1 - if the tree is perfect.
 *         0 - otherwise
 */
int is_perfect(const binary_tree_t *root, int d, int level) {
	/* Check if the tree is empty */
	if (!root)
		return (1);

	/* Check the presence of children */
	if (!root->left && !root->right)
		return (d == level + 1);

	if (!root->left || !root->right)
		return (0);

	return (is_perfect(root->left, d, level + 1) &&
		is_perfect(root->right, d, level + 1));
}

/*
 * binary_tree_is_perfect - Wrap is_perfect function.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 0 - if tree is NULL or not perfect.
 *         1 - otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree) {
	int d = 0;
	const binary_tree_t *tmp;

	/* Evaluate the tree depth */
	tmp = tree;
	while (tmp)
	{
		d++;
		tmp = tmp->left;
	}
	return (is_perfect(tree, d, 0));
}
