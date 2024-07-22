#include "sort.h"
#include <stdio.h>

/**
 * swap_node - The function that swap two adjacent nodes in a doubly linked
 * list.
 * @list: The pointer to the head of the list
 * @a: The first node
 * @b: The second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a == NULL || b == NULL || a == b)
	{
		return;
	}

	if (a->prev)
	{
		a->prev->next = b;
	}
	else
	{
		*list = b;
	}
	if (b->next)
	{
		b->next->prev = a;
	}

	a->next = b->next;
	b->prev = a->prev;
	b->next = a;
	a->prev = b;

	print_list(*list);
}

/**
 * cocktail_forward_pass - The function that performs the forward pass of
 * Cocktail shaker sort algorithm.
 * @list: The pointer to the head of the list
 * @start: The starting node
 * @end: The ending node
 *
 * Return: 1 if nodes were swapped, 0 otherwise
 */
int cocktail_forward_pass(listint_t **list, listint_t **start, listint_t **end)
{
	int swapped = 0;
	listint_t *current = *start;

	while (current->next != *end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			swapped = 1;
		}
		else
		{
			current = current->next;
		}
	}
	*end = current;
	return (swapped);
}

/**
 * cocktail_backward_pass - The function that performs the backward pass of
 * Cocktail shaker sort algorithm.
 * @list: The pointer to the head of the list
 * @start: The starting node
 * @end: The ending node
 *
 * Return: 1 if nodes were swapped, 0 otherwise
 */
int cocktail_backward_pass(listint_t **list, listint_t **start, listint_t
		**end)
{
	int swapped = 0;
	listint_t *current = *end;

	while (current->prev != *start)
	{
		if (current->n > current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			swapped = 1;
		}
		else
		{
			current = current->prev;
		}
	}
	*start = current;
	return (swapped);
}

/**
 * cocktail_sort_list - The function that sorts a doubly linked list of
 * integers in ascending order using the Cocktail shaker sort algorithm.
 * @list: The pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = *list;
	listint_t *end = NULL;

	if (list == NULL || *list == NULL)
	{
		return;
	}
	while (swapped)
	{
		swapped = cocktail_forward_pass(list, &start, &end);
		if (!swapped)
		{
			break;
		}
		swapped = cocktail_backward_pass(list, &start, &end);
	}
}
