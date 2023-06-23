#include "sort.h"

/**
 * find_seq - find the largest sequence
 * @size: array size
 * Return: 0
 */
size_t find_seq(size_t size)
{
	size_t count;

	for (count = 1; count < size; count = (count * 3) + 1)
	{
		;
	}
	return ((count - 1) / 3);
}

/**
 * shell_sort - a function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: array to be sorted
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	int tmp;
	size_t m, n, gap;

	if (array == NULL || size == 0)
		return;
	for (gap = find_seq(size); gap; gap = (gap - 1) / 3)
	{
		for (m = gap; m < size; m++)
		{
			tmp = array[m];
			for (n = m; n > gap - 1 && array[n - gap] > tmp; n -= gap)
				array[n] = array[n - gap];
			array[n] = tmp;
		}
	}
	print_array(array, size);
}
