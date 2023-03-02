#include "binary_trees.h"

/**
 * _avl_insert - Help insert a value into an AVL tree recursively.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @parent: The parent node of the current working node.
 * @new: A double pointer to store the new node.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the new root after insertion, or NULL on failure.
 */
avl_t *_avl_insert(avl_t **tree, avl_t *parent, avl_t **new, int value)
{
	int val = value, bfactor;

	if (!*tree)
		return (*new = binary_tree_node(parent, val));

	if ((*tree)->n > val)
	{
		(*tree)->left = _avl_insert(&(*tree)->left, *tree, new, val);
		if (!(*tree)->left)
			return (NULL);
	}
	else if ((*tree)->n < val)
	{
		(*tree)->right = _avl_insert(&(*tree)->right, *tree, new, val);
		if (!(*tree)->right)
			return (NULL);
	}
	else
		return (*tree);

	bfactor = binary_tree_balance(*tree);
	if (bfactor > 1 && (*tree)->left->n > value)
		*tree = binary_tree_rotate_right(*tree);
	else if (bfactor < -1 && (*tree)->right->n < value)
		*tree = binary_tree_rotate_left(*tree);
	else if (bfactor > 1 && (*tree)->left->n < value)
	{
		(*tree)->left = binary_tree_rotate_left((*tree)->left);
		*tree = binary_tree_rotate_right(*tree);
	}
	else if (bfactor < -1 && (*tree)->right->n > value)
	{
		(*tree)->right = binary_tree_rotate_right((*tree)->right);
		*tree = binary_tree_rotate_left(*tree);
	}

	return (*tree);
}

/**
 * avl_insert - Wrap the _avl_insert function.
 * @tree: A double pointer to the root node of the AVL tree to insert into.
 * @value: The value to insert into the AVL tree.
 *
 * Return: A pointer to the inserted node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	_avl_insert(tree, *tree, &new, value);
	return (new);
}
