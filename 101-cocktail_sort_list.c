#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - The function swaps two adjacent nodes in a doubly linked list
 * @list: he pointer to the head of the doubly linkd list
 * @left: The left node to be swapped
 * @right: The right node to be swapped
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
	{
		left->prev->next = right;
	}
	else
	{
		*list = right;
	}
	if (right->next)
	{
		right->next->prev = left;
	}
	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
	print_list(*list);
}

/**
 * cocktail_sort_forward - The function that sorts the list forward using
 * cocktail shaker sort.
 * @list: The pointer to the head of the list
 * @start: The starting node.
 * @end: The ending node.
 *
 * Return: 1 if nodes were swapped, 0 otherwise
 */
int cocktail_sort_forward(listint_t **list, listint_t **start, listint_t **end)
{
	int swapped = 0;
	listint_t *current = *start;

	while (current != *end && current->next != NULL)
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
 * cocktail_sort_backward - The function that sorts the list backward
 * using a cocktail shaker sort.
 * @list: The pointer to the head of the list.
 * @start: The starting node.
 * @end: The ending node
 *
 * Return: 1 if nodes were swapped, 0 otherwise.
 */
int cocktail_sort_backward(listint_t **list, listint_t **start, listint_t
		**end)
{
	listint_t *current = *end;
	int swapped = 0;

	while (current != *start && current->prev != NULL)
	{
		if (current->n < current->prev->n)
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
 * integers in ascending order using the Cocktail shaker sort algorithm
 * @list: The pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start, *end;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}
	start = *list;
	end = NULL;
	do {
		swapped = cocktail_sort_forward(list, &start, &end);
		if (swapped)
		{
			swapped = cocktail_sort_backward(list, &start, &end);
		}
	} while (swapped);
}
