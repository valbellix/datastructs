/**
 * @file bst.h
 * @author Valerio Bellizia
 *
 * This file contains the interface to be used with ds_bst. It implements 
 * a binary search tree using a linked structure.
 */

#ifndef bin_tree_h
#define bin_tree_h

#include "result.h"
#include "defs.h"

#include <stddef.h>

/**
 * This is an opaque structure that represents a binary tree
 */
typedef struct ds_bst ds_bst;

/**
 * This is an opaque structure that represents a binary tree node.
 */
typedef struct ds_bst_node ds_bst_node;

/**
 * This is a structure that represents an iterator for a binary tree
 */
typedef struct ds_bst_iterator {
	const ds_bst* bst;
	ds_bst_node* current;
} ds_bst_iterator;

/**
 * This represents the supported visiting strategies.
 */
typedef enum ds_visit_type { DFS_PRE_ORDER, DFS_IN_ORDER, DFS_POST_ORDER } ds_visit_type;

/**
 * This function will move the iterator forward.
 * 
 * @param it The iterator.
 */
void ds_bst_iterator_next(ds_bst_iterator* it);

/**
 * This function will move the iterator backward.
 * 
 * @param it The iterator.
 */
void ds_bst_iterator_prev(ds_bst_iterator* it);

/**
 * This function can be used to check if the iterator is valid.
 *
 * @param it The iterator.
 * 
 * @return it returns 1 if the iterator is valid, 0 otherwise.
 */
int ds_bst_iterator_is_valid(ds_bst_iterator* it);

/**
 * This function will get the element pointed by the iterator as const void*.
 *
 * @param it The iterator.
 * 
 * @return The pointer to the element stored into the current element held iterator.
 */
const void* ds_bst_iterator_get(ds_bst_iterator* it);

/**
 * This function will get the typed pointer to the element pointed by the iterator.
 * 
 * @param TYPE The type we want as output.
 * @param IT The iterator.
 * 
 * @return The pointer to the element stored into the tree casted to the given type.
 */
#define ds_bst_iterator_get_ptr(TYPE, IT) ((TYPE*)ds_bst_iterator_get(IT))

/**
 * This function will get the value of the element pointed by the iterator.
 *
 * @param TYPE The type we want as output.
 * @param IT The iterator.
 *
 * @return The value to the element stored into the tree casted to the given type.
 */
#define ds_bst_iterator_get_value(TYPE, IT) (*(TYPE*)ds_bst_iterator_get(IT))

/**
 * This function will create a binary tree node by copying the element passed as argument.
 * 
 * @param element The element to store in the node.
 * @param the size of the element to store in the node.
 * 
 * @return It returns the pointer to a new instance of ds_bst_node.
 */
ds_bst_node* create_ds_bst_node(const void* element, ds_cmp cmp, const size_t size);

/**
 * This function will release the memory allocated to the node.
 * 
 * @param node It is the node to free.
 */
void delete_ds_bst_node(ds_bst_node* node);

/**
 * This function will return the pointer to the left child.
 *
 * @param node The node.
 * 
 * @return It returns a pointer to the left child.
 */
ds_bst_node* ds_bst_node_left(ds_bst_node* node);

/**
 * This function will return the pointer to the right child.
 *
 * @param node The node.
 * 
 * @return It returns a pointer to the right child.
 */
ds_bst_node* ds_bst_node_right(ds_bst_node* node);

/**
 * This function will return 1 if the node is a leaf (i.e. it has no children).
 *
 * @param node The node.
 * 
 * @return It returns 1 if the node has no children (i.e. it is a leaf).
 */
int ds_bst_node_is_leaf(ds_bst_node* node);


/**
 * This function will return a pointer to the element stored within the node as const void*.
 *
 * @param node The node.
 * 
 * @return It returns a pointer to the element store within the node.
 */
const void* ds_bst_node_get(ds_bst_node* node);

/**
 * This function will get the typed pointer to the element stored within the node.
 * 
 * @param TYPE The type we want as output.
 * @param NODE The node.
 * 
 * @return The pointer to the element stored within the node casted to the given type.
 */
#define ds_bst_node_get_ptr(TYPE, NODE) ((TYPE*)ds_bst_node_get(NODE))

/**
 * This function will get the value of the element stored within the node.
 * 
 * @param TYPE The type we want as output.
 * @param NODE The node.
 * 
 * @return The value of the element stored within the node casted to the given type.
 */
#define ds_bst_node_get_value(TYPE, NODE) (*(TYPE*)ds_bst_node_get(NODE))

// Binary Tree interface

/**
 * This function will create an instance of ds_bst.
 *
 * @param cmp_func This is the pointer to a function that will be used to compare two elements.
 * @param size It is the size of the element that a list node is supposed to store.
 * 
 * @return It returns the pointer to a new instance of ds_bst
 */
ds_bst* create_ds_bst(ds_cmp cmp_func, const size_t size);

/**
 * This function will release the memory allocated to the binary tree.
 * Elements stored in the list will be freed using 'free'.
 *
 * @param bt The binary tree.
 */
void delete_ds_bst(ds_bst* bt);

/**
 * This function will return the comparison function used by the binary tree.
 * 
 * @param bt The binary tree.
 * 
 * @return The comparison function.
 */
ds_cmp ds_bst_cmp(ds_bst* bt);

/**
 * This function will return the number of elements store in the binary tree.
 *
 * @param bt The binary tree.
 * 
 * @return The number of elements stored in the binary tree.
 */
size_t ds_bst_size(const ds_bst* bt);

/**
 * This function will insert an element into the binary tree.
 *
 * @param bt The binary tree.
 * @param element The element.
 * 
 * @return The result of the operation. The function will return ELEMENT_ALREADY_EXISTS if attempts to insert a duplicate.
 */
ds_result ds_bst_insert(ds_bst* bt, const void* element);

/**
 * This function will remove an element into the binary tree if exists.
 *
 * @param bt The binary tree.
 * @param element The element.
 * @return The result of the operation.
 */
ds_result ds_bst_remove(ds_bst* bt, const void* element);

/**
 * This function will look for an element into the binary tree.
 *
 * @param bt The binary tree.
 * @param element The element.
 * 
 * @return It returns 1 if the element exists, 0 otherwise.
 */
int ds_bst_search(ds_bst* bt, const void* element);

/**
 * This function will look for an element into the binary tree, if exists it will
 * return a pointer to the element, NULL otherwise.
 * 
 * @param bt The binary tree.
 * @param element The element we are looking for.
 * 
 * @return It returns a pointer to the element into the binary tree if such element exists, NULL otherwise.
 */
const void* ds_bst_get(ds_bst* bt, const void* element);

/**
 * This function will return the maximum value into the binary tree.
 *
 * @param bt The binary tree.
 * 
 * @return The maximum value stored in the binary tree.
 */
const void* ds_bst_max(ds_bst* bt);

/**
 * This function will return the minimum value into the binary tree.
 *
 * @param bt The binary tree.
 * 
 * @return The minimum value stored in the binary tree.
 */
const void* ds_bst_min(ds_bst* bt);

/**
 * This function will return an iterator to the first (smallest) element of the binary tree.
 * 
 * @param bt The binary tree.
 * 
 * @return The iterator to the smallest element of the binary tree.
 */
ds_bst_iterator ds_bst_first(ds_bst* bt);

/**
 * This function will return an iterator to the last (biggest) element of the binary tree.
 * 
 * @param bt The binary tree.
 * 
 * @return The iterator to the biggest element of the binary tree.
 */
ds_bst_iterator ds_bst_last(ds_bst* bt);

/**
 * This function will implement a custom visit on tree nodes using a specified visiting strategy.
 *
 * @param bt The binary tree.
 * @param visit_func The function that will be used to visit the element within the node. It is a function like func(const void*, void*) where the first argument is the pointer to the current ds_bst_node instance, and the second is an optional argument that may be used with this function to passa data.
 * @param other_args It is the second argument to pass visit_func.
 * @param type The type of the tree visit.
 */
void ds_bst_visit(ds_bst* bt, void (*visit_func)(const void*, void*), void* other_args, ds_visit_type type);

#endif
