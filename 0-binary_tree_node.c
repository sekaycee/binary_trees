#include "binary_tree.h"

/*
 * binary_tree_node - Create a binary tree node
 * @parent: Pointer to the parent node of the to create
 * @value: Value to be put in the new node
 *
 * Return: Pointer to the new node if success..
 * 	otherwise return NULL
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (!new_node)
		return (NULL);

	new_node->parent = parent;
	new_node->value = value;
	new_node->left = NULL;
	new_node->rightt = NULL;

	return (new_node);
}
