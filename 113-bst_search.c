#include "binary_trees.h"

/**
 * bst_search - searches for a value in the Binary Search Tree
 *
 * @tree: a pointer to the root node of the BST to search.
 * @value: the value to search in the tree
 *
 * Return: a pointer to the node containing a value equal to @value
 * or NULL if nothing is found
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	while (tree != NULL)
	{
		if (value == tree->n)
			return ((bst_t *)tree);
		if (value < tree->n)
			tree = tree->left;
		else
			tree = tree->right;
	}
	return (NULL);
}
