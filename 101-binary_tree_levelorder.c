#include "binary_trees.h"
#include "queue.c"

/**
 * binary_tree_levelorder - goes through a binary tree
 * using level-order traversal
 *
 * @tree: a pointer to the root node of the tree
 * @func: a pointer to a function to call for each node
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *queue;
	const binary_tree_t *node;

	if (tree == NULL || func == NULL)
		return;

	queue = create_queue();
	if (queue == NULL)
		return;

	enqueue(queue, (binary_tree_t *)tree);

	while (!is_empty(queue))
	{
		node = dequeue(queue);

		func(node->n);

		if (node->left != NULL)
			enqueue(queue, node->left);

		if (node->right != NULL)
			enqueue(queue, node->right);
	}

	delete(queue);
}
