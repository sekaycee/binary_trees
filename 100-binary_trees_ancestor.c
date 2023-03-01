#include "binary_trees.h"

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: NULL - if no common ancestors.
 *         Common ancestor - otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mum, *dad;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mum = first->parent;
	dad = second->parent;
	if (mum == second || !dad || (!dad->parent && mum))
		return (binary_trees_ancestor(mum, second));
	else if (first == dad || !mum || (!mum->parent && dad))
		return (binary_trees_ancestor(first, dad));
	return (binary_trees_ancestor(mum, dad));
}
