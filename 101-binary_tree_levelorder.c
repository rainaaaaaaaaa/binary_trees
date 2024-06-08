#include "binary_trees_plus.h"

/**
 * binary_tree_size - calculates the size of a tree
 * @tree: tree
 * Return: size
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * save - converts a tree to an arr in level-order traversal
 * @tree: tree
 * @tree_arr: tree array
 * @index: index
 */
void save(const binary_tree_t *tree, int *tree_arr, int index)
{
	if (!tree)
		return;
	tree_arr[index] = tree->n;
	if (tree->left)
		save(tree->left, tree_arr, (2 * index) + 1);
	if (tree->right)
		save(tree->right, tree_arr, (2 * index) + 2);
}

/**
 * binary_tree_levelorder - function that goes through
 * a binary tree using level-order traversal
 * @tree: tree
 * @func: printing function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	int size, j;
	int *tree_arr;

	if (!tree || !func)
		return;
	size = binary_tree_size(tree);
	tree_arr = calloc(size, sizeof(int));
	save(tree, tree_arr, 0);
	for (j = 0; j < size; j++)
		func(tree_arr[j]);
	free(tree_arr);
}
