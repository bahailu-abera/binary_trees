#include "binary_trees.h"

/**
 * is_perfect - checks if a tree is perfect
 *
 * @tree: a pointer to the root of the tree
 * @level: the maximum depth of the tree
 * @depth: the depth of the current node
 *
 * Return: 1 if it is perfect otherwise 0.
 */
int is_perfect(const binary_tree_t *tree, int level, int depth)
{
	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
	{
		if (depth == level)
			return (1);
		return (0);
	}

	if (tree->left != NULL && tree->right != NULL)
		return (is_perfect(tree->left, level, depth + 1) &&
			is_perfect(tree->right, level, depth + 1));
	return (0);
}

/**
 * tree_height - measures the size of a binary tree
 *
 * @tree: a pointer to the tree to measure the size
 *
 * Return: the size of the tree
 */
int tree_height(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);
	left_height = tree_height(tree->left);
	right_height = tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 *
 * @tree: a pointer to the the root node of the tree to check
 *
 * Return: 1 if it is perfect otherwise 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int level;

	level = tree_height(tree);

	return (is_perfect(tree, level, 0));
}
