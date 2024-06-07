#include "binary_trees.h"

/**
 * binary_tree_depth - measures the depth of a node in a binary tree
 * @tree: tree
 * Return: depth
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree && tree->parent)
		return (1 + binary_tree_depth(tree->parent));
	return (0);
}

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: first
 * @second: second
 * Return: a pointer
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t dep1, dep2;
	const binary_tree_t *t1, *t2;

	dep1 = binary_tree_depth(first);
	dep2 = binary_tree_depth(second);

	if (dep1 == 0 || dep2 == 0)
		return (NULL);


	t1 = first;
	t2 = second;
	if (dep1 > dep2)
	{
		while (dep1 != dep2)
		{
			t1 = t1->parent;
			dep1--;
		}
	}
	else if (dep1 < dep2)
	{
		while (dep1 != dep2)
		{
			t2 = t2->parent;
			dep2--;
		}
	}

	while (t1 != t2)
	{
		t1 = t1->parent;
		t2 = t2->parent;
	}

	return ((binary_tree_t *)t1);
}
