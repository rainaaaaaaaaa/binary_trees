#include "binary_trees.h"


/**
 * binary_tree_height - calculate the height of a binary tree
 * @tree: the binary tree
 * Return: number of nodes
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t lev, riv, max;

	if (tree == NULL)
		return (0);

	lev = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	riv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	max = lev > riv ? lev : riv;
	return (max);
}

/**
 * binary_tree_balance - check if a binary tree is balanced or not
 * Description: check if all nodes have a left/right nodes
 *
 * @tree: the binary tree
 * Return: 0 not balanced | 1 balanced
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	size_t lev, riv;

	if (tree == NULL)
		return (0);

	lev = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	riv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	return (lev - riv);
}
