#include "sort.h"

void swap_items(int *array_item1, int *array_item2);

/**
 * selection_sort - sorts an array using a selection sort algorithm
 * @array: the array to be sorted
 * @size: the length of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int smallest;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		if (array[smallest] < array[i])
		{
			swap_items(&array[i], &array[smallest]);
			print_array(array, size);
		}
	}
}

/**
 * swap_items - interchanges two items
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
