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
 * avl_remove - Remove a node from a AVL tree.
 * @root: A pointer to the root of the tree.
 * @value: The value to remove.
 *
 * Return: The modified tree - if success.
 *         NULL - on failure
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *tmp;
	int balance;

	if (!root)
		return root;

	if (value < root->n)
		root->left = avl_remove(root->left, value);
	else if (value > root->n)
		root->right = avl_remove(root->right, value);
	else
	{
		if (!root->left || !root->right)
		{
			tmp = root->left ? root->left : root->right;
			if (!tmp) {
				tmp = root;
				root = NULL;
			} else
				*root = *tmp;
			free(tmp);
		}
		else
		{
			tmp = min_value_node(root->right);
			root->n = tmp->n;
			root->right = avl_remove(root->right, tmp->n);
		}
	}

	if (!root)
		return (root);

	balance = binary_tree_balance(root);
	if (balance > 1 && binary_tree_balance(root->left) >= 0)
		return (binary_tree_rotate_right(root));

	if (balance > 1 && binary_tree_balance(root->left) < 0)
	{
		root->left = binary_tree_rotate_left(root->left);
		return (binary_tree_rotate_right(root));
	}

	if (balance < -1 && binary_tree_balance(root->right) <= 0)
		return (binary_tree_rotate_left(root));

	if (balance < -1 && binary_tree_balance(root->right) > 0)
	{
		root->right = binary_tree_rotate_right(root->right);
		return (binary_tree_rotate_left(root));
	}
	return (root);
}

