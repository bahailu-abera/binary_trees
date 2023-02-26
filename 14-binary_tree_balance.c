#include "binary_trees.h"

/**
 * _tree_height - measures the height of a tree
 *
 * @tree: a pointer to the root node of the tree
 *
 * Return: the height of the tree
 */
int _tree_height(const binary_tree_t *tree)
{
	int lh, rh;

	if (tree == NULL)
		return (1);
	lh = _tree_height(tree->left);
	rh = _tree_height(tree->right);

	return ((lh > rh ? lh : rh) + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 *
 * @tree: a pointer to the root node of the tree to be measure balance factor
 *
 * Return: the balance factor of the tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);
	left_height = _tree_height(tree->left);
	right_height = _tree_height(tree->right);

	return (left_height - right_height);
}
