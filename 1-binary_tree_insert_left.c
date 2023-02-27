#include "binary_trees.h"

/**
 * binary_tree_insert_left - Insert a node as a left-child of
 *                           of another in a binary tree.
 * @parent: A pointer to the node to insert the left-child in.
 * @value: The value to store in the new node.
 *
 * Return: If parent is NULL or an error occurs - NULL.
 *         Otherwise - a pointer to the new node.
 *
 * Description: If parent already has a left-child, the new node
 *              takes its place and the old left-child is set as
 *              the left-child of the new node.
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	if (!parent)
		return (NULL);

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = parent->left;
	new_node->right = NULL;
	if (parent->left)
		parent->left->parent = new_node;

	parent->left = new_node;

	return (new_node);
}
