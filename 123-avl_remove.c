#include "binary_trees.h"

/**
 * bfactor - Measure balance factor of a AVL.
 * @tree: Pointer to the tree to go through.
 *
 * Return: Balance factor - if success
 *         Nothing - on failure
 */
void bfactor(avl_t **tree)
{
	int bval;

	if (!tree || !*tree)
		return;
	if (!(*tree)->left && !(*tree)->right)
		return;

	bfactor(&(*tree)->left);
	bfactor(&(*tree)->right);
	bval = binary_tree_balance((const binary_tree_t *)*tree);
	if (bval > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (bval < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}
/**
 * successor - Get the next successor.
 *             the min node in the right subtree
 * @node: Pointer to the tree to check
 *
 * Return: The min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (!node)
		return (0);

	left = successor(node->left);
	if (left == 0)
		return (node->n);

	return (left);
}
/**
 * remove_type - Remove a node depending on its children
 * @root: node to remove
 *
 * Return: 0 - if it has no children.
 *         Other value - if it has
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	new_value = successor(root->right);
	root->n = new_value;
	return (new_value);
}
/**
 * bst_remove - Remove a node from a BST tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - remove a node from a AVL tree
 * @root: root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);

	bfactor(&root_a);
	return (root_a);
}
