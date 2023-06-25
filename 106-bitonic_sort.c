#include "sort.h"

/**
 * print_seq - prints the array to be sorted
 * @array: array to be printed
 * @lb: lower bound
 * @ub: upper bound
 */
void print_seq(int *array, int lb, int ub)
{
	char *seq;

	for (seq = ""; lb <= ub; lb++)
	{
		printf("%s%d", seq, array[lb]);
		seq = ", ";
	}
	printf("\n");
}

/**
 * swap_ele - swaps elements
 * @array: array containing elements to be swapped
 * @one: first element
 * @two: second element
 * @bound: direction for swaping
 */
void swap_ele(int *array, int one, int two, int bound)
{
	int tmp;

	if (bound == (array[one] > array[two]))
	{
		tmp = array[one];
		array[one] = array[two];
		array[two] = tmp;
	}
}

/**
 * merge_seque - bitonically merges the sequence
 * @array: array to be merged
 * @lb: lower bound
 * @ub: higher bound
 * @bound: direction for merging
 * @size: size of the array
 */
void merge_seque(int *array, size_t lb, size_t ub, int bound, size_t size)
{
	size_t m, n, mid;

	if (ub - lb < 1)
		return;
	mid = (lb + ub) / 2;
	for (m = lb, n = mid + 1; m <= mid; m++, n++)
		swap_ele(array, m, n, bound);
	merge_seque(array, lb, mid, bound, size);
	merge_seque(array, mid + 1, ub, bound, size);
}

/**
 * make_seque - making the sequence using bitonic
 * @array: array to be made
 * @lb: lower bound
 * @ub: upper bound
 * @bound: dirction for making
 * @size: array size
 */
void make_seque(int *array, size_t lb, size_t ub, int bound, size_t size)
{
	char *dir;
	size_t mid;

	if (ub - lb < 1)
		return;
	dir = bound ? "UP" : "DOWN";
	printf("Merging [%ld/%ld] (%s):\n", ub - lb + 1, size, dir);
	print_seq(array, lb, ub);

	mid = (lb + ub) / 2;
	make_seque(array, lb, mid, 1, size);
	make_seque(array, mid + 1, ub, 0, size);

	merge_seque(array, lb, ub, bound, size);
	printf("Result [%ld/%ld] (%s):\n", ub - lb + 1, size, dir);
	print_seq(array, lb, ub);
}

/**
 * bitonic_sort - a function that sorts an array of integers in
 * ascending order using the Bitonic sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	make_seque(array, 0, size - 1, 1, size);
}
