#include "sort.h"

/**
 * swap_eles - swap 2 elements
 * @x: first ele
 * @y: sec ele
 */
void swap_eles(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

/**
 * bubble_sort - array ascending sort
 * @array: array to be sorted
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, length = size;
	int test = 0;

	if (array == NULL || size < 2)
		return;

	while (test == 0)
	{
		test = 1;
		for (i = 0; i < length - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_eles(array + i, array + i + 1);
				print_array(array, size);
				test = 0;
			}
		}
		length--;
	}
}
