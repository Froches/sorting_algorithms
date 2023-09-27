#include "sort.h"

/**
 * swap - Swaps two integers in an array
 * @array: The array whose elements it will swap
 * @i: The index of first integer
 * #j: The index of second integer
 */
void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

/**
 * lomuto_partition - The Lomuto partition scheme
 * @array: The array to partition
 * @low: The low point of partition
 * @high: The high part of partition
 * @size: The size of the array
 * Return: i + 1
 */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int j;
	int i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			swap(array, i, j);
			print_array(array, size);
		}
	}
	swap(array, i + 1, high);
	print_array(array, size);

	return i + 1;
}

/**
 * quick_sort_helper - A helper function for the quick sort function
 * @array: The array to sort
 * @low: The low point
 * @high: The high point
 * @size: The size of the array
 */

void quick_sort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		quick_sort_helper(array, low, partition_index - 1, size);
		quick_sort_helper(array, partition_index + 1, high, size);
	}
}

/**
 * quick_sort - Implementing the quick sort algorithm
 * @array: The array of ints to sort
 * @size: The size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (size < 2 || array == NULL)
		return;

	quick_sort_helper(array, 0, size - 1, size);
}
