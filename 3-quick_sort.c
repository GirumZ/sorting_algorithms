#include "sort.h"

/**
 * swap_items - swaps two items in an array
 * @array_item1: the first item
 * @array_item2: the second item
 */

void swap_items(int *array_item1, int *array_item2)
{
	int tmp;

	tmp = *array_item1;
	*array_item1 = *array_item2;
	*array_item2 = tmp;
}


/**
 * lomuto_partition - partitions an array using the lomuto scheme
 * @array: the array to be sorted
 * @size: the size of the array
 * @lb: lower bound to the array
 * @ub: upper bound to the array
 *
 * Return: the index of the pivot element
 */

int lomuto_partition(int *array, size_t size, int lb, int ub)
{
	int start, itr;
	int *pivot;

	pivot = &array[ub];
	for (start = itr = lb; itr < ub; itr++)
	{
		if (array[itr] < *pivot)
		{
			if (start < itr)
			{
				swap_items(&array[itr], &array[start]);
				print_array(array, size);
			}
			start++;
		}
	}
	if (array[start] > *pivot)
	{
		swap_items(&array[start], pivot);
		print_array(array, size);
	}

	return (start);
}



/**
 * lomuto_sort - recursively sort an array uising quick sort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 * @lb: lower bound to the array
 * @ub: upper boubd to the array
 */

void lomuto_sort(int *array, size_t size, int lb, int ub)
{
	int pivot_index;

	if (lb < ub)
	{
		pivot_index = lomuto_partition(array, size, lb, ub);
		lomuto_sort(array, size, lb, pivot_index - 1);
		lomuto_sort(array, size, pivot_index + 1, ub);
	}
}

/**
 * quick_sort - sorts an array using a quick sort algorithm and lomuto scheme
 * @array: the array to be sorted
 * @size: the size of the array
 */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}

