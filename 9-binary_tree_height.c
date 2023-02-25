#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 *
 * @tree: a pointer to the root node of the tree to measure the height
 *
 * Return: the height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height = 0;

	if (!tree)
		return (height);

	while (tree != NULL)
	{
		height++;
		if (tree->left != NULL)
			tree = tree->left;
		else
			tree = tree->right;
	}

	return (height - 1);
}
