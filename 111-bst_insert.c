#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a binary search tree
 *
 * @tree: a double pointer to the root node of the BST
 * @value: the value to store in the node to be inserted
 *
 * Return: a pointer to the created node or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new, *p, *cur;

	if (tree == NULL)
		return (NULL);
	p = NULL;
	cur = *tree;

	while (cur != NULL)
	{
		p = cur;
		if (cur->n == value)
			return (NULL);
		if (cur->n < value)
			cur = cur->right;
		else
			cur = cur->left;
	}
	new = (bst_t *)binary_tree_node(p, value);
	if (new == NULL)
		return (NULL);
	/** the tree is empty **/
	if (p == NULL)
		*tree = new;
	else if (value < p->n)
		p->left = new;
	else
		p->right = new;
	return (new);
}
