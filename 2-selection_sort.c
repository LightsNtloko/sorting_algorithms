#include "sort.h"
#include <stdio.h>

/**
 * selection_sort - A function that sorts an array of integers in ascending
 * order using a Selection sort algorithm
 * @array: The array of integers to be sorted
 * @size: The size of the array
 */
void selection_sort(int *array, size_t size)
{
	size_t a, b, minimum_index;
	int temp;

	if (!array || size < 2)
	{
		return;
	}
	for (a = 0; a < size - 1; a++)
	{
		minimum_index = a;
		for (b = a + 1; b < size; b++)
		{
			if (array[b] < array[minimum_index])
			{
				minimum_index = b;
			}
			if (minimum_index != a)
			{
				temp = array[a];
				array[a] = array[minimum_index];
				array[minimum_index] = temp;
				print_array(array, size);
			}
		}
	}
}
