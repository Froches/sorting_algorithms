#include "sort.h"

/**
 * swap - swaps two integers in an array
 * @i: first integer to swap
 * @j: second integer to swap
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}

/**
 * partition - orders a subset of an array of integers according to
 * the Lomuto scheme
 * @array: array of integers
 * @size: size of the array
 * @low: lowest index of the subset to order
 * @high: highest index of the subset to order
 * Return: final partition index
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}

/**
 * lomuto_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 * @low: lowest index of the subset to sort
 * @high: highest index of the subset to sort
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(array, size, low, high);

		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
