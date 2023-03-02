#include "binary_trees.h"

/**
 * min_value_node - Find inorder successor.
 * @node: A pointer to the node to be removed.
 *
 * Return: A pointer to the inorder successive node
 */
bst_t *min_value_node(bst_t *node)
{
	bst_t *current = node;

	/* Find the leftmost leaf */
	while (current && current->left)
		current = current->left;

	return (current);
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: A pointer to the root node of the BST to remove a node from.
 * @value: The value to remove in the BST.
 *
 * Return: A pointer to the new root node after deletion.
 *
 * Description: If the node to be deleted has two children, it
 *              is replaced with its first in-order successor.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	/* Return if the tree is empty */
	if (!root)
		return (root);

	/* Find the node to be deleted */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		/* If the node is with only one child or no child */
		if (!root->left)
		{
			bst_t *tmp = root->right;
			free(root);
			return (tmp);
		}
		if (!root->right)
		{
			bst_t *tmp = root->left;
			free(root);
			return (tmp);
		}

		/* If the node has two children */
		bst_t *tmp = min_value_node(root->right);

		/* Place successor in position of the node to be deleted */
		root->n = tmp->n;

		/* Delete the inorder successor */
		root->right = bst_remove(root->right, tmp->n);
	}
	return (root);
}
