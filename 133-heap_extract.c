#include "binary_trees.h"

/**
 * heap_extract - extracts the root node from a Max Binary Heap.
 * @root: A pointer to the heap root.
 *
 * Return: The value of extracted node - if success
 *         0 - on failure
 **/
int heap_extract(heap_t **root)
{
	heap_t *node;
	int max_element;

	if (!*root)
		return (0);

	/* Extract the maximum element (i.e., the root) */
	max_element = (*root)->n;

	/* Find the node to remove (i.e., the rightmost leaf) */
	*node = *root;
	while (node->left || node->right)
	{
		if (!node->right || node->left->n >= node->right->n)
	    		node = node->left;
		else
	    		node = node->right;
	}

	/* Replace the root with the node to remove */
	(*root)->n = node->n;
	if (node->parent)
	{
		if (node == node->parent->left)
			node->parent->left = NULL;
		else
			node->parent->right = NULL;
	}
	else
		*root = NULL;

	/* Free the memory used by the node to remove */
	free(node);

	return (max_element);
}
