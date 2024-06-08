#include "binary_trees_plus.h"

/**
 * binary_tree_rotate_left - function that performs
 * a left-rotation on a binary tree
 * @tree: tree
 * Return: pointer to the root node of the tree to rotate
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rchild;

	if (!tree || !tree->right)
		return (NULL);

	rchild = tree->right;
	tree->right = rchild->left;

	rchild->parent = tree->parent;
	if (!tree->parent)
		;
	else if (tree == tree->parent->right)
		tree->parent->right = rchild;
	else
		tree->parent->left = rchild;

	tree->parent = rchild;
	rchild->left = tree;

	return (rchild);
}
