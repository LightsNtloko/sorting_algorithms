#include "sort.h"
#include <stdio.h>

/**
 * swap - The function that swaps two elements in an array
 * @c: The first element
 * @d: The second element
 */
void swap(int *c, int *d)
{
	int temp = *c;
	*c = *d;
	*d = temp;
}

/**
 * partition - The Lomuto partition scheme for Quick sort
 * @array: The array to be sorted
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 * @size: The size of the array
 *
 * Return: The index of the pivot
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int a = start;
	int b;

	for (b = start; b < end; b++)
	{
		if (array[b] < pivot)
		{
			if (a != b)
			{
				swap(&array[a], &array[b]);
				print_array(array, size);
			}
			a++;
		}
	}
	if (a != end)
	{
		swap(&array[a], &array[end]);
		print_array(array, size);
	}
	return (a);
}

/**
 * quick_sort_helper - The helper function for Quick sort
 * @array: The array to be sorted
 * @start: The starting index of the partition
 * @end: The ending index of the partition
 * @size: The size of the array
 */
void quick_sort_helper(int *array, int start, int end, size_t size)
{
	if (start < end)
	{
		int pi = partition(array, start, end, size);
		quick_sort_helper(array, start, pi - 1, size);
		quick_sort_helper(array, pi + 1, end, size);
	}
}

/**
 * quick_sort - The function that sorts ana array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
	{
		return;
	}
	quick_sort_helper(array, 0, size - 1, size);
}
