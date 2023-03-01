#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_successor - finds a in order successor of a node
 *
 * @node: a pointer to the node to find the successor
 *
 * Return: a pointer to the successor of the node
 */
bst_t *bst_successor(bst_t *node)
{
    if (node == NULL)
        return NULL;

    if (node->right != NULL)
    {
        node = node->right;
        while (node->left != NULL)
            node = node->left;
        return node;
    }

    while (node->parent != NULL && node->parent->right == node)
        node = node->parent;

    return node->parent;
}

/**
 * bst_shift - shifts two nodes in a binary tree
 *
 * @tree: a pointer to the root node of the tree
 * @u: a pointer to a node to be replaced
 * @v: a pointer to the second node to be shifted
 *
 * Return: void
 */
void bst_shift(bst_t **tree, bst_t *u, bst_t *v)
{
    if (u->parent == NULL)
        *tree = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v != NULL)
        v->parent = u->parent;
}

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
    if (tree == NULL)
        return NULL;

    if (value == tree->n)
        return (bst_t *)tree;

    if (value < tree->n)
        return bst_search(tree->left, value);
    else
        return bst_search(tree->right, value);
}

/**
 * bst_remove - removes a node from a Binary Search Tree
 *
 * @root: a pointer to the root node of the tree where we will remove a node
 * @value: the value to remove in the tree
 *
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
    bst_t *node, *successor;

    node = bst_search(root, value);
    if (node == NULL)
        return root;

    if (node->left == NULL && node->right == NULL)
    {
        bst_shift(&root, node, NULL);
    }
    else if (node->left == NULL || node->right == NULL)
    {
        bst_shift(&root, node, (node->left != NULL ? node->left : node->right));
    }
    else
    {
        successor = bst_successor(node);
        bst_shift(&root, successor, successor->right);
        bst_shift(&root, node, successor);
        successor->left = node->left;
        successor->left->parent = successor;
        if (node->right != successor)
        {
            successor->right = node->right;
            successor->right->parent = successor;
        }
    }

    free(node);
    return root;
}
