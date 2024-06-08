#include "binary_trees_plus.h"

/**
 * binary_tree_is_bst - check if bt is bst
 * @tree: tree
 * Return: 0 or 1
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int pre;

	if (!tree)
		return (0);
	pre = INT_MIN;
	return (unordered(tree, &pre));
}

/**
 * unordered - helper
 * @tree: tree
 * @pre: pre
 * Return: 0 or 1
 */
int unordered(const binary_tree_t *tree, int *pre)
{
	if (!tree)
		return (1);
	if (!unordered(tree->left, pre))
		return (0);
	if (*pre >= tree->n)
		return (0);
	*pre = tree->n;
	return (unordered(tree->right, pre));
}
