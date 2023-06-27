#include "sort.h"

/**
 * quick_sort_help - sorts positions
 * @array: array to be sorted
 * @size: array size
 * @one: first value
 * @two: second value
 */
void quick_sort_help(int *array, size_t size, int one, int two)
{
	int piv;

	if (one < two)
	{
		piv = qs_partition(array, size, one, two);
		quick_sort_help(array, size, one, piv - 1);
		quick_sort_help(array, size, piv + 1, two);
	}
}

/**
 * swapp - swaps array elements
 * @one: first element
 * @two: second element
 */
void swapp(int *one, int *two)
{
	int tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}
/**
 * qs_partition - sorts partition
 * @array: array to undergo sorting
 * @low: lower bound
 * @up: upper bound
 * @size: array size
 * Return: m
 */
int qs_partition(int *array, int low, int up, size_t size)
{
	int piv, m, n;

	piv = array[up];
	m = low;
	for (n = low; n < up; n++)
	{
		if (array[n] < piv)
		{
			if (m != n)
			{
				swapp(&array[m], &array[n]);
				print_array(array, size);
			}
			m++;
		}
	}
	if (piv != array[m])
	{
		swapp(&array[m], &array[up]);
		print_array(array, size);
	}
	return (m);
}

/**
 * quick_sort - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
	{
		return;
	}
	quick_sort_help(array, size, 0, size - 1);
}
