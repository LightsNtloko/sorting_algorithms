#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/**
 * struct listint_s - The doubly linked list node
 *
 * @n: The integer stored in the node
 * @prev: The pointer to the previous element of the list
 * @next: The pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *left, listint_t *right);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *c, int *d, int *array, size_t size);
int partition(int *array, int start, int end, size_t size);
void quick_sort_helper(int *array, int start, int end, size_t size);

#endif /* SORT_T */
