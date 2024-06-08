#ifndef _BINARY_TREES_PLUS_H_
#define _BINARY_TREES_PLUS_H_

#include "binary_trees.h"
#include <limits.h>
#include <math.h>

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
