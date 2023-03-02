#include "binary_trees.h"

/**
 * heap_to_sorted_array - Convert a Binary Max Heap
 * to a sorted array of integers.
 * @heap: A pointer to the root node of the heap to convert.
 * @size: The address to store the size of the array.
 *
 * Return: The pointer to array sorted in descending order - if success
 *         0 - on failure
 **/
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	size_t sorted, count = 0, index = 0, front = 0, rear = 0;
	heap_t *node = heap;
	heap_t **queue;

	while (node = node->right)
		count++;

	sorted = malloc(count * sizeof(size_t));
	if (!sorted)
	{
		*size = 0;
		return (NULL);
	}

	queue = malloc(count * sizeof(heap_t *));
	if (!queue) {
		free(sorted);
		*size = 0;
		return (NULL);
	}

	queue[rear++] = heap;
	while (front < rear)
	{
		heap_t *node = queue[front++];
		sorted[index++] = node->n;
		if (node->left)
	    		queue[rear++] = node->left;
		if (node->right)
			queue[rear++] = node->right;
	}
	free(queue);
	*size = count;
	return (sorted);
}
