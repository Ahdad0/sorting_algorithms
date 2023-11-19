#include "sort.h"
#include <stdbool.h>

/**
 * swap_arr - swap two index
 *
 * @get: swapped with to
 * @to: swapped with get
 */
void swap_arr(int *get, int *to)
{
	int temp;

	temp = *get;
	*get = *to;
	*to = temp;
}

/**
 * bubble_sort -  sorts an array of integers in ascending order
 *
 * @array: array of integer
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int check;

	for (i = 0; i < size - 1; i++)
	{
		check = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_arr(&array[j], &array[j + 1]);
				print_array(array, size);
				check = 1;
			}
		}

		if (check == 0)
		{
			break;
		}
	}
}
