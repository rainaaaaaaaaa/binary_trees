#include "binary_trees_plus.h"

/**
 * binary_tree_rotate_right - function that performs
 * a right-rotation on a binary tree
 * @tree: tree
 * Return: pointer to the root node of the tree to rotate
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *lchild;

	if (!tree || !tree->left)
		return (NULL);

	lchild = tree->left;
	if (lchild->right)
		lchild->right->parent = tree;
	tree->left = lchild->right;

	lchild->parent = tree->parent;
	if (!tree->parent)
		;
	else if (tree == tree->parent->right)
		tree->parent->right = lchild;
	else
		tree->parent->left = lchild;

	tree->parent = lchild;
	lchild->right = tree;

	return (lchild);
}
