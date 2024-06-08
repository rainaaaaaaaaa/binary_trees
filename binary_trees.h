#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <math.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;

/* Binary Search Tree */
typedef struct binary_tree_s bst_t;

/* AVL Tree */
typedef struct binary_tree_s avl_t;

/* Max Binary Heap */
typedef struct binary_tree_s heap_t;

/*hh*/
/**
 * struct QueueNode - node of the queue
 * @node: node
 * @next: next
 */
typedef struct QueueNode
{
        heap_t *node;
        struct QueueNode *next;
} queueNode_t;

/**
 * struct Queue_s - queue structure
 * @head: head
 * @tail: tail
 */
typedef struct Queue_s
{
        struct QueueNode *head;
        struct QueueNode *tail;
} queue_t;

/* Binary Tree Printer */
void binary_tree_print(const binary_tree_t *);


binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
void binary_tree_delete(binary_tree_t *tree);
int binary_tree_is_leaf(const binary_tree_t *node);
int binary_tree_is_root(const binary_tree_t *node);
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
size_t binary_tree_height(const binary_tree_t *tree);
size_t binary_tree_depth(const binary_tree_t *tree);
size_t binary_tree_size(const binary_tree_t *tree);
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_balance(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
int binary_tree_is_complete(const binary_tree_t *tree);

void save(const binary_tree_t *tree, int *tree_arr, int index);
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);

int binary_tree_is_bst(const binary_tree_t *tree);
int unordered(const binary_tree_t *tree, int *pre);
bst_t *bst_insert(bst_t **tree, int value);
bst_t *array_to_bst(int *array, size_t size);
bst_t *bst_search(bst_t *tree, int value);
bst_t *bst_remove(bst_t *root, int value);

int binary_tree_is_avl(const binary_tree_t *tree);
avl_t *avl_insert(avl_t **tree, int value);
avl_t *array_to_avl(int *array, size_t size);
avl_t *avl_remove(avl_t *root, int value);
avl_t *sorted_array_to_avl(int *array, size_t size);

int binary_tree_is_heap(const binary_tree_t *tree);
heap_t *heap_insert(heap_t **root, int value);
avl_t *array_to_heap(int *array, size_t size);

int checks(const binary_tree_t *root, int index, int size);
int unordered(const binary_tree_t *tree, int *pre);
bst_t *iNsertnode(bst_t **tree, bst_t *node);
void avl_balancer(avl_t **tree, int val);
avl_t *avl_search(avl_t *tree, int value);
void arr_avl(avl_t **tree, avl_t *pp, int *arr, int lo, int hi);
int is_heap(const binary_tree_t *tree);
queue_t *createQ();
void addQ(queue_t *queue, heap_t *node);
heap_t *popQ(queue_t *queue);
heap_t *levels(const heap_t *tree);
void sortHeap(heap_t **root, heap_t *node);

#endif
