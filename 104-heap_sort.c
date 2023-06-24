#include "sort.h"

/**
 * build_down - builds heap upwards
 * @array: array to be sorted
 * @sta: root of the heap
 * @size: array size
 * @end: last element of the heap
 */
void build_down(int *array, size_t sta, size_t size, size_t end)
{
	size_t baby, swapp, root;

	root = sta;
	while ((root * 2) + 1 <= end)
	{
		/*left child subscription*/
		baby = (root * 2) + 1;
		swapp = root;
		if (array[swapp] < array[baby])
		{
			/*swap root*/
			swapp = baby;
		}
		/*when one child is > other*/
		if (swapp != root)
		{
			elem_swap(array, size, &array[root], &array[swapp]);
			root = swapp;
		}
		return;
	}
}

/**
 * heapy - arrange the heap with root being the largest number
 * @array: array to be sorted
 * @size: array size
 */
void heapy(int *array, size_t size)
{
	int sta;

	sta = (size / 2) - 1;
	while (sta >= 0)
	{
		build_down(array, sta, size - 1, size);
		sta--;
	}
}

/**
 * elem_swap - swaps array elements
 * @array: array to be swiped
 * @size: array size
 * @m: first element
 * @n: second element
 */
void elem_swap(int *array, size_t size, int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
	print_array(array, size);
}

/**
 * heap_sort - a function that sorts an array of integers in ascending
 * order using the Heap sort algorithm
 * @array: array to be heaped
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	size_t end;

	if (!array || size < 2)
		return;
	end = size - 1;
	heapy(array, size);

	while (end > 0)
	{
		elem_swap(array, size, &array[end], &array[0]);
		end--;
		build_down(array, 0, end, size);
	}
}
