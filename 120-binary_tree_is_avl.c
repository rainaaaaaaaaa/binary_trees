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
	int lev, riv;

	if (tree == NULL)
		return (1);

	if (binary_tree_balance(tree->left) == 0
	    || binary_tree_balance(tree->right) == 0)
		return (0);

	lev = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	riv = tree->right ? 1 + binary_tree_height(tree->right) : 0;

	if (abs(lev - riv) > 1)
		return (0);

	return (1);
}

/**
 * binary_tree_is_avl - check if a binary tree is AVL
 * @tree: binary tree
 * Return: 0 (not AVL) | 1 (is AVL)
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int isbst, isbalance;

	if (tree == NULL)
		return (0);

	isbst = binary_tree_is_bst(tree);
	isbalance = binary_tree_balance(tree);

	if (isbst && isbalance)
		return (1);

	return (0);
}
