#include "binary_trees.h"

/**
 * _insert - check if node is inserted
 * @tree: A pointer to the tree root
 * @value: The node value
 *
 * Return: The pointer to the new node - if success
 *         NULL - on failure
 */
bst_t *_insert(bst_t **tree, int value)
{
	if (value < (*tree)->n)
	{
		if (!(*tree)->left)
		{
			(*tree)->left = binary_tree_node(*tree, value);
			return ((*tree)->left);
		}
		else
			return (_insert(&((*tree)->left), value));
	}

	if (value > (*tree)->n)
	{
		if (!(*tree)->right)
		{
			(*tree)->right = binary_tree_node(*tree, value);
			return ((*tree)->right);
		}
		else
			return (_insert(&((*tree)->right), value));
	}

	return (NULL);
}

/**
 * bst_insert - Insert a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node - if success.
 *         NULL -  on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	if (!*tree)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	return (_insert(tree, value));
}
