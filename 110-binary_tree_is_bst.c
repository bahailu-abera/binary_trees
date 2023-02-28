#include "binary_trees.h"
#include <limits.h>

/**
 * _is_bst - checks if a binary tree is a valid binary search tree
 *
 * @tree: a pointer to the root node of the tree
 * @min: the minimum value that the nodes can have in the subtree
 * @max: the maximum value that the nodes can have in the subtree
 *
 * Return: 1 if the tree is a valid BST, and 0 otherwise
 */
int _is_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);
	if (tree->n <= min || tree->n >= max)
		return (0);
	return (_is_bst(tree->left, min, tree->n) &&
		_is_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - checks is a binary tree is valid binary search tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (_is_bst(tree, INT_MIN, INT_MAX));
}
