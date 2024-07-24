#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * find_maximum - The function that finds the maximum value in the array.
 * @array: The array to search.
 * @size: The size of the array.
 * Return: The maximum value in the array.
 */
int find_maximum(int *array, size_t size)
{
	int maximum = array[0];
	size_t k;

	for (k = 1; k < size; k++)
	{
		if (array[k] > maximum)
		{
			maximum = array[k];
		}
	}
	return (maximum);
}

/**
 * init_count_array - The function that initializes the count array.
 * @count: The count array.
 * @maximum: The maximum value in the array.
 */
void init_count_array(int *count, int maximum)
{
	int k;

	for (k = 0; k <= maximum; k++)
	{
		count[k] = 0;
	}
}

/**
 * fill_count_array - The function that fills the count array with frequencies
 * of elements.
 * @count: The count array.
 * @size: The size of the array.
 */
void fill_count_array(int *array, int *count, size_t size)
{
	size_t k;

	for (k = 0; k < size; k++)
	{
		count[array[k]]++;
	}
}

/**
 * cumulative_count - The function that updates the count array to cumulative
 * counts.
 * @count: The count array.
 * @maximum: The maximum value in the array.
 */
void cumulative_count(int *count, int maximum)
{
	int k;

	for (k = 1; k <= maximum; k++)
	{
		count[k] += count[k - 1];
	}
}

/**
 * counting_sort - The function that sorts an array of integers in ascending
 * order using the Counting sort algorithm.
 * @array: The pointer to the array to be sorted.
 * @size: The number of elements in the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *output;
	size_t k;
	int maximum;

	if (array == NULL || size < 2)
	{
		return;
	}
	maximum = find_maximum(array, size);
	count = malloc((maximum + 1) * sizeof(int));
	if (count == NULL)
	{
		return;
	}
	output = malloc(size * sizeof(int));
	if (output == NULL)
	{
		free(count);
		return;
	}
	init_count_array(count, maximum);
	fill_count_array(array, count, size);
	cumulative_count(count, maximum);
	for (k = size; k > 0; k--)
	{
		output[count[array[k - 1]] - 1] = array[k - 1];
		count[array[k - 1]]--;
	}
	for (k = 0; k < size; k++)
	{
		array[k] = output[k];
	}
	print_array(count, maximum + 1);
	free(count);
	free(output);
}
