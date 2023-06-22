#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers
 * in ascending order using the Selection sort algorith
 * @array: array to be selected
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t count1, count2, min_idx;
	int tmp;

	for (count1 = 0; count1 < size - 1; count1++)
	{
		min_idx = count1;
		for (count2 = count1 + 1; count2 < size; count2++)
		{
			if (array[count2] < array[min_idx])
			{
				min_idx = count2;
			}
		}
		if (min_idx != count1)
		{
			tmp = array[count1];
			array[count1] = array[min_idx];
			array[min_idx] = tmp;
			print_array(array, size);
		}
	}
}
