#include "binary_trees.h"

/**
 * bst_search - searches for a value in a BST
 * @tree: tree
 * @value: value
 * Return: pointer
 */
bst_t *bst_search(bst_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return (tree);
	if (value < tree->n)
		return (bst_search(tree->left, value));
	if (value > tree->n)
		return (bst_search(tree->right, value));
	return (NULL);
}
