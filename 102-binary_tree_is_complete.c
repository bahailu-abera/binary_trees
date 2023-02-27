#include "binary_trees.h"
#include "queue.c"

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete otherwise 0.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	queue_t *q;

	if (tree == NULL)
		return (0);
	q = create_queue();
	enqueue(q, (binary_tree_t *)tree);
	while (!is_empty(q))
	{
		tree = dequeue(q);
		if (tree == NULL)
			break;
		enqueue(q, tree->left);
		enqueue(q, tree->right);
	}

	while (!is_empty(q))
	{
		if (dequeue(q) != NULL)
			return (0);
	}

	delete(q);
	return (1);
}
