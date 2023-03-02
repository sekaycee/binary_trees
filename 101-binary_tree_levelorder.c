#include "binary_trees.h"

/**
 * binary_tree_levelorder - Traverse a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	const binary_tree_t *current;
	binary_tree_t **queue = NULL;
	size_t front = 0, rear = 0, i;

	if (!tree || !func)
		return;

	queue = malloc(sizeof(binary_tree_t *) * binary_tree_size(tree));
	if (!queue)
		return;

	queue[rear++] = (binary_tree_t *)tree;
	while (front < rear)
	{
		current = queue[front++];
		func(current->n);
		if (current->left)
			queue[rear++] = current->left;
		if (current->right)
			queue[rear++] = current->right;
	}

	for (i = 0; i < rear; i++)
		queue[i] = NULL;

	free(queue);
}
