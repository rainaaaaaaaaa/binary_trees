#include "binary_trees_plus.h"

/**
 * array_to_avl - function that builds a Binary
 * Search Tree from an array
 * @array: array
 * @size: size
 * Return: node or NULL
 */
avl_t *array_to_avl(int *array, size_t size)
{
	int j;
	bst_t *root = NULL;

	if (!array)
		return (NULL);
	for (j = 0; j < (int)size; j++)
		avl_insert(&root, array[j]);
	return (root);
}
