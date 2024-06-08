#include "binary_trees.h"

avl_t *avl_search(avl_t *tree, int value);
/**
 * avl_remove - function that removes a node from a BST
 * @root: root
 * @value: value
 * Return: node or 0
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *r_node, *heir;

	r_node = avl_search(root, value);
	if (!r_node)
		return (NULL);
	if (r_node->left && r_node->right)
	{
		for (heir = r_node->right; heir && heir->left;)
			heir = heir->left;
		r_node->n = heir->n;
		r_node = heir;
	}
	if (r_node->left)
	{
		r_node->left->parent = r_node->parent;
		if (r_node == r_node->parent->right)
			r_node->parent->right = r_node->left;
		else
			r_node->parent->left = r_node->left;
	}
	else if (r_node->right)
	{
		r_node->right->parent = r_node->parent;
		if (r_node == r_node->parent->right)
			r_node->parent->right = r_node->right;
		else
			r_node->parent->left = r_node->right;
	}
	else
	{
		if (r_node == r_node->parent->right)
			r_node->parent->right = NULL;
		else
			r_node->parent->left = NULL;
		r_node->parent = NULL;
	}
	free(r_node);
	return (root);

}

/**
 * avl_search - searches for a value in a BST
 * @tree: tree
 * @value: value
 * Return: pointer
 */
avl_t *avl_search(avl_t *tree, int value)
{
	if (!tree)
		return (NULL);
	if (value == tree->n)
		return (tree);
	if (value < tree->n)
		return (avl_search(tree->left, value));
	if (value > tree->n)
		return (avl_search(tree->right, value));
	return (NULL);
}
