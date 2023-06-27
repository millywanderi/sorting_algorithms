#include "sort.h"

/**
 * swaps - swaps array elements
 * @array: array with elements to be swapped
 * @one: first element
 * @two: second element
 */
void swaps(int *array, size_t one, size_t two)
{
	int temp;

	temp = array[one];
	array[one] = array[two];
	array[two] = temp;
}

/**
 * partition_hoare - hoare partition
 * @array: array to be partitioned
 * @one: first element
 * @two: second element
 * @size: array size
 * Return: return the last sorted element posistion
 */
int partition_hoare(int *array, int one, int two, int size)
{
	int piv = array[two];
	int curr = one - 1, find = two + 1;

	while (1)
	{
		do {
			curr++;
		} while (array[curr] < piv);
		do {
			find--;
		} while (array[find] > piv);
		if (curr >= find)
			return (curr);
		swaps(array, curr, find);
		print_array(array, size);
	}
}

/**
 * q_sort - implement quick sort alogarithm
 * @array: array to be implemented
 * @one: first element
 * @two: second element
 * @size: array size
 */
void q_sort(int *array, ssize_t one, ssize_t two, int size)
{
	ssize_t pos = 0;

	if (one < two)
	{
		pos = partition_hoare(array, one, two, size);
		q_sort(array, one, pos - 1, size);
		q_sort(array, pos, two, size);
	}
}

/**
 * quick_sort_hoare - a function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
