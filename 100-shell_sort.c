#include "sort.h"
#include <stdio.h>

/**
 * shell_sort - The function that sorts an array of integers in ascending
 * order using the Shell sort algorithm with the Knuth sequence.
 * @array: The array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap;
	size_t a, b;
	int temp;

	if (array == NULL || size < 2)
	{
		return;
	}
	gap = 1;
	while (gap < size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap >= 1)
	{
		for (a = gap; a < size; a++)
		{
			temp = array[a];
			b = a;

			while (b >= gap && array[b - gap] > temp)
			{
				array[b] = array[b - gap];
				b -= gap;
			}
			array[b] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
