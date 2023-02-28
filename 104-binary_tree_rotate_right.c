#include "binary_trees.h"

/**
 * binary_tree_rotate_right - performs a right rotation on a binary tree
 *
 * @tree: a pointer to the root node of a binary tree to rotate
 *
 * Return: a pointer to the new root of the tree after rotation
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_root;

	if (tree == NULL || tree->left == NULL)
		return (tree);
	new_root = tree->left;
	tree->left = new_root->right;
	new_root->right = tree;
	tree->parent = new_root;
	new_root->parent = NULL;

	return (new_root);
}
