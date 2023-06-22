#include "sort.h"

/**
 * swapping - swaps positions
 * @array: array to be swapped
 * @one: first index
 * @two: second index
 */
void swapping(int **array, size_t one, size_t two)
{
	int hold;

	hold = (*array)[one];
	(*array)[one] = (*array)[two];
	(*array)[two] = hold;
}

/**
 * bubble_sort- sorts an array of integers in ascending order
 * @array: array to be sorted
 * @size: array size
 */
void bubble_sort(int *array, size_t size)
{
	size_t count1, count2, flagging;

	if (size < 2)
	{
		return;
	}
	for (count1 = 0; count1 < size; count1++)
	{
		flagging = 0;
		for (count2 = 0; count2 < size - count1 - 1; count2++)
		{
			if (array[count2] > array[count2 + 1])
			{
				swapping(&array, count2, count2 + 1);
				print_array(array, size);
				flagging = 1;
			}
		}
		if (!flagging)
			break;
	}
}
