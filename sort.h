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
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
int cocktail_sort_backward(listint_t **list, listint_t **start, listint_t
		**end);
int cocktail_sort_forward(listint_t **list, listint_t **start, listint_t
		**end);
void counting_sort(int *array, size_t size);
int find_maximum(int *array, size_t size);
void init_count_array(int *count, int maximum);
void fill_count_array(int *array, int *count, size_t size);
void cumulative_count(int *count, int maximum);
void counting_sort(int *array, size_t size);

#endif /* SORT_T */
