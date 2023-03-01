#include "binary_trees.h"

/**
  * _height - Measure the height of a binary tree
  * @tree: Pointer to the node to measures the height
  *
  * Return: The height of the tree
  */
static size_t _height(const binary_tree_t *tree)
 {
         size_t height_l;
         size_t height_r;

         height_l = tree->left ? 1 + _height(tree->left) : 0;
         height_r = tree->right ? 1 + _height(tree->right) : 0;
         return (height_l > height_r ? height_l : height_r);
 }


/**
 * get_level - Get nodes at the same level.
 * @tree: A pointer to the root node of the tree to traverse.
 * @level: The level of the node
 * @func: A pointer to a function to call for each node.
 */
void get_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;

	if (level == 1)
		func(tree->n);
	else if (level > 1)
	{
		get_level(tree->left, level - 1, func);
		get_level(tree->right, level - 1, func);
	}
}


/**
 * binary_tree_levelorder - Traverse a binary tree using
 *                          level-order traversal.
 * @tree: A pointer to the root node of the tree to traverse.
 * @func: A pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t i, height;

	if (!tree || !func)
		return;

	height = _height(tree);
	for (i = 1; i <= height; i++)
		get_level(tree, i, func);
}
