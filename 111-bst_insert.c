#include "binary_trees.h"

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
	bst_t *new_node;

	new_node = malloc(sizeof(bst_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	if (!*tree)
	{
		/* create a new node and return it */
		*tree = new_node;
		return (*tree);
	}
	if (value < (*tree)->n)
		 /* insert value into the left subtree */
		(*tree)->left = bst_insert(&((*tree)->left), value);
	else if (value > (*tree)->n)
		 /* insert value into the right subtree */
		(*tree)->right = bst_insert(&((*tree)->right), value);
	/* If the value is already present in the tree, do nothing */
	return (*tree);
}
