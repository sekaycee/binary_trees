#include "binary_trees.h"

/**
 * heap_insert - Insert a value in Max Binary Heap.
 * @root: A double pointer to the root node of the Heap.
 * @value: The value to store in the node to be inserted.
 *
 * Return: A pointer to the created node - if success
 *         NULL - on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *current = *root, *parent = NULL;

	/* Create the new node */
	new_node = malloc(sizeof(heap_t));
	if (!new_node)
		return (NULL);

	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;
	/* Find the position to insert the new node */
	while (current && new_node->n > current->n)
	{
		parent = current;
		current = current->right;
	}

	/* Insert the new node */
	new_node->left = current;
	if (parent)
		parent->right = new_node;
	else
		*root = new_node;

	return (new_node);
}
