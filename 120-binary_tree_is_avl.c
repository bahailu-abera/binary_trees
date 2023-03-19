#include "binary_trees.h"
#include <stdlib.h>
#include <limits.h>


#define max(a, b) ((a) > (b) ? (a) : (b))


/**
 * is_valid - helper function for binary_tree_is_avl
 *
 * @tree: a pointer to the root node of the tree
 * @min: the possible minimum value for the subtree
 * @max: the possible maximum value for the subtree
 *
 * Return: 1 if the tree is valid otherwise 0
 */
int is_valid(const binary_tree_t *tree, int min, int max)
{
	int left_height, right_height;

	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	left_height = is_valid(tree->left, min, tree->n);
	right_height = is_valid(tree->right, tree->n, max);

	if (!left_height || !right_height || (abs(left_height - right_height) > 1))
		return (0);

	return (max(left_height, right_height) + 1);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is valid otherwise 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid(tree, INT_MIN, INT_MAX) > 0);
}
