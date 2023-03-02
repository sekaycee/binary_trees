#include "binary_trees.h"

void heapify_down(heap_t *root)
{
	int tmp;
	heap_t *current = root;

	/* Percolate down the new root node */
	while (current->left || current->right)
	{
		if (!current->left)
		{
	    		if (current->n < current->right->n)
			{
				tmp = current->n;
				current->n = current->right->n;
				current->right->n = tmp;
				current = current->right;
			}
			break;
		}
		else if (!current->right)
		{
			if (current->n < current->left->n) {
				tmp = current->n;
				current->n = current->left->n;
				current->left->n = tmp;
				current = current->left;
	    		}
			break;
	    	}
		else if (current->left->n > current->right->n)
		{
	    		if (current->n < current->left->n)
			{
				tmp = current->n;
				current->n = current->left->n;
				current->left->n = tmp;
				current = current->left;
			}
			break;
	    	}
		else
		{
	    		if (current->n < current->right->n)
	    		{
				tmp = current->n;
				current->n = current->right->n;
				current->right->n = tmp;
				current = current->right;
			}
			break;
		}
	}
}

int heap_extract(heap_t **root)
{
	int root_value;
	heap_t *max_node = *root;

	if (!*root)
		return (0);

	/* If the root node is a leaf, just delete it */
	root_value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (root_value);
	}

	/* Find the node with the maximum value */
	while (max_node->left || max_node->right)
	{
		if (!max_node->left)
			max_node = max_node->right;
		else if (!max_node->right)
			max_node = max_node->left;
		else if (max_node->left->n > max_node->right->n)
			max_node = max_node->left;
		else
			max_node = max_node->right;
	}

	/* Swap the maximum node with the root node */
	(*root)->n = max_node->n;
	if (max_node->parent != *root)
		max_node->parent->right = NULL;
	else
		(*root)->left = NULL;

	free(max_node);
	heapify_down(&(*root));

	return (root_value);
}

