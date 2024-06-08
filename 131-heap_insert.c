#include "binary_trees_plus.h"

/**
 * createQ - create a queue
 * Return: queue
 */
queue_t *createQ()
{
	queue_t *queue = (queue_t *)malloc(sizeof(queue_t));

	queue->head = NULL;
	queue->tail = NULL;
	return (queue);
}

/**
 * addQ - add a new node to the queue
 * @queue: queue
 * @node: node to queue
 */
void addQ(queue_t *queue, heap_t *node)
{
	queueNode_t *newNode = (queueNode_t *)malloc(sizeof(queueNode_t));

	newNode->node = node;
	newNode->next = NULL;

	if (queue->tail == NULL)
	{
		queue->head = newNode;
		queue->tail = newNode;
		return;
	}
	queue->tail->next = newNode;
	queue->tail = newNode;
}


/**
 * popQ - pop the head of the queue
 * @queue: queue
 * Return: node poped
 */
heap_t *popQ(queue_t *queue)
{
	queueNode_t *tmp;
	heap_t *node;

	if (queue->head == NULL)
		return (NULL);

	tmp = queue->head;
	node = tmp->node;
	queue->head = queue->head->next;

	if (queue->head == NULL)
		queue->tail = NULL;

	free(tmp);
	return (node);
}

/**
 * levels - traverse a binary tree level by level
 * @tree: tree
 * Return: height
 */
heap_t *levels(const heap_t *tree)
{
	queue_t *queue;
	heap_t *actual = NULL;
	int flag = 0;

	if (tree == NULL)
		return (NULL);

	queue = createQ();
	addQ(queue, (binary_tree_t *)tree);

	while (queue->head != NULL)
	{
		if (!flag)
		{
			actual = popQ(queue);
			if (actual->left != NULL)
				addQ(queue, actual->left);
			else
				flag = 1;
			if (actual->right != NULL)
				addQ(queue, actual->right);
			else
				flag = 1;
		}
		else
			popQ(queue);
	}
	free(queue);
	return (actual);
}

/**
 * sortHeap - fix position of inserted node to keep tree a Max Heap
 * @root: Max Heap tree
 * @node: new node
 */
void sortHeap(heap_t **root, heap_t *node)
{
	heap_t *tparent, *tL = NULL, *tR = NULL;

	if (node->parent == NULL)
	{
		(*root) = node;
		return;
	}
	if (node->parent->n > node->n || (*root)->left == NULL)
		return;
	tparent = node->parent, tL = node->left, tR = node->right;
	if (tparent->parent)
	{
		node->parent = tparent->parent;
		if (node->parent->left == tparent)
			node->parent->left = node;
		else
			node->parent->right = node;
	}
	if (tparent->left == node)
	{
		node->left = tparent, node->right = tparent->right;
		if (tparent->right)
			tparent->right->parent = node;
	}
	else
	{
		node->right = tparent, node->left = tparent->left;
		if (tparent->left)
			tparent->left->parent = node;
	}
	tparent->left = NULL, tparent->right = NULL;
	if (tL)
		tparent->left = tL, tL->parent = tparent;
	if (tR)
		tparent->right = tR, tR->parent = tparent;
	if (tparent == (*root))
		*root = node, (*root)->parent = NULL;
	tparent->parent = node;
	if (node->parent && node->parent->n < node->n)
		sortHeap(root, node);
}

/**
 * heap_insert - insert a node in the Heap tree
 * @root: Heap tree
 * @value: value of the new node
 * Return: node to the created node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *pp = NULL, *newNode = NULL;

	if (*root == NULL)
		return (*root = binary_tree_node(NULL, value));

	pp = levels(*root);
	newNode = binary_tree_node(pp, value);
	if (newNode == NULL)
		return (NULL);

	if (pp->left == NULL)
		pp->left = newNode;
	else
		pp->right = newNode;

	sortHeap(root, newNode);
	return (newNode);
}
