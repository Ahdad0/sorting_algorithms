#include "sort.h"

/**
 * partition - array partition
 *
 * @array: array to sort
 * @low: first position
 * @high: last position
 * @size: array size
 *
 * Return: int pivot index
 */
int partition(int *array, int low, int high, size_t size)
{
	int i = low - 1, a, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < array[high])
		{
			i++;
			if (i < j)
			{
				a = array[i];
				array[i] = array[j];
				array[j] = a;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[high])
	{
		a = array[i + 1];
		array[i + 1] = array[high];
		array[high] = a;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_range_lomuto - sorts an array of
 * integers  recursively
 *
 * @array: array to sort
 * @low: first position
 * @high: last position
 * @size: array size
 */
void quick_sort_range_lomuto(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_range_lomuto(array, low, pivot - 1, size);
		quick_sort_range_lomuto(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers using the Quick
 * sort algorithm in ascending order
 *
 * @array: array to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_range_lomuto(array, 0, size - 1, size);
	}
}
