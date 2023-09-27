#include "sort.h"

int lomuto_partition(int *array, int low, int high);
void quick_sort_helper(int *array, int low, int high);

/**
 * lomuto_partition - The Lomuto partition scheme
 * @array: The array to partition
 * @low: The low point of partition
 * @high: The high part of partition
 * Return: i + 1
 */

int lomuto_partition(int *array, int low, int high)
{
	int pivot = array[high];
	int temp, j, i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			temp = array[i];
			array[i] = array[j];
			array[j] = temp;

			print_array(array, high - low + 1);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;

	print_array(array, high - low + 1);

	return i + 1;
}

/**
 * quick_sort_helper - A helper function for the quick sort function
 * @array: The array to sort
 * @low: The low point
 * @high: The high point
 */

void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high);

		quick_sort_helper(array, low, partition_index - 1);
		quick_sort_helper(array, partition_index + 1, high);
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

	quick_sort_helper(array, 0, size - 1);
}
