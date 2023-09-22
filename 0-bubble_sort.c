#include "sort.h"

void swap_items(int *array_item1, int *array_item2);

/**
 * bubble_sort - sorts a list using the bubble sort algorithm
 * @array: pointer to the array
 * @size: the size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	bool swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;

		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_items(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
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
