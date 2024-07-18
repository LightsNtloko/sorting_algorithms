#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - The function that sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm.
 * @list: The double pointer to the head of the list
 * @left: The pointer to the left node
 * @right: The pointer to the right node
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
	{
		left->prev->next  = right;
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
 * insertion_sort_list - The function that sort a doubly linked list.
 * @list: The double pointer to the head of the list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
	{
		return;
	}

	current = (*list)->next;
	while (current)
	{
		temp = current;
		while (temp->prev && temp->n < temp->prev->n)
		{
			swap_nodes(list, temp->prev, temp);
		}
		current = current->next;
	}
}
