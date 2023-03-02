#include "binary_trees.h"

/**
 * _height - measures the height of a binary tree
 * @tree: tree root
 * Return: height
 */
size_t _height(const binary_tree_t *tree)
{
	size_t left = 0;
	size_t right = 0;

	if (!tree)
		return (0);

	left = _height(tree->left);
	right = _height(tree->right);
	if (left > right)
		return (left + 1);

	return (right + 1);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf
 * @node: pointer to the node to check
 * Return: 1 if node is a leaf, otherwise 0
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	int leaf = 0;

	if (node && !(node->left) && !(node->right))
		leaf = 1;

	return (leaf);
}

/**
 * check_parent - checks if node has a lower/higher than its grand parent
 * @tree: actual node
 * Return: 1 if actual node has an appropiartely value, 0 otherwise
 */
int check_parent(const binary_tree_t *tree)
{
	const binary_tree_t *p;
	const binary_tree_t *grand_p;

	if (!tree || !tree->parent || !tree->parent->parent)
		return (1);

	p = tree->parent;
	grand_p = p->parent;
	while (p && grand_p)
	{
		if (p->n < grand_p->n && tree->n >= grand_p->n)
			return (0);
		if (p->n > grand_p->n && tree->n <= grand_p->n)
			return (0);

		p = p->parent;
		grand_p = p->parent;
	}
	return (1);
}

/**
 * _is_bst - checks if binary tree is a BST
 * @tree: tree root
 * Return: 1 if tree is a BST, 0 otherwise
 */
int _is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (binary_tree_is_leaf(tree))
		return (1);

	if (tree->left && tree->left->n >= tree->n)
		return (0);

	if (tree->right && tree->right->n <= tree->n)
		return (0);

	if (!check_parent(tree->left) || !check_parent(tree->right))
		return (0);

	return (_is_bst(tree->left) && _is_bst(tree->right));
}

/**
 * binary_tree_is_avl - checks if tree is AVL
 * @tree: tree root
 * Return: 1 if tree is a AVL, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree && _is_bst(tree) &&
	    (_height(tree->left) - _height(tree->right) == 0))
		return (1);

	return (0);
}
