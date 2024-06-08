#include "binary_trees.h"

/**
 * arr_avl - create an AVL tree from a sorted array
 * @tree: AVL tree
 * @pp: parent node
 * @arr: array of int
 * @lo: low index
 * @hi: high index
 */
void arr_avl(avl_t **tree, avl_t *pp, int *arr, int lo, int hi)
{
	avl_t *node;
	int mid = (lo + hi) / 2;

	if (lo > hi)
		return;
	if (lo == hi)
	{
		node = binary_tree_node(pp, arr[mid]);
		if (node == NULL)
			return;
		if (pp->n < node->n)
			pp->right = node;
		else
			pp->left = node;
		return;
	}
	node = binary_tree_node(pp, arr[mid]);
	if (node == NULL)
		return;
	if (pp == NULL)
		(*tree) = node;
	else
	{
		if (pp->n < node->n)
			pp->right = node;
		else
			pp->left = node;
	}
	arr_avl(tree, node, arr, lo, mid - 1); /*left*/
	arr_avl(tree, node, arr, mid + 1, hi); /*right*/
}
/**
 * sorted_array_to_avl - sorted array to AVL tree
 * @array: sorted array of int
 * @size: size of the array
 * Return: pointer to the AVL tree | NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;

	if (array == NULL || size == 0)
		return (NULL);

	if (size == 1)
		tree = binary_tree_node(NULL, array[0]);
	else
		arr_avl(&tree, tree, array, 0, size - 1);
	return (tree);
}
