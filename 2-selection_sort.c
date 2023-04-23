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
 * selection_sort - ascending order of an array
 * @array: array to be sorted
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t x, y;

	if (array == NULL || size < 2)
		return;

	for (x = 0; x < size - 1; x++)
	{
		min = array + x;
		for (y = x + 1; y < size; y++)
			min = (array[y] < *min) ? (array + y) : min;

		if ((array + x) != min)
		{
			swap_eles(array + x, min);
			print_array(array, size);
		}
	}
}
