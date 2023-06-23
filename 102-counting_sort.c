#include "sort.h"

/**
 * init_zero - initializes zero to an array
 * @array: array to undergo initialization
 * @size: array size
 */
void init_zero(int *array, int size)
{
	int m;

	for (m = 0; m < size; m++)
	{
		array[m] = 0;
	}
}

/**
 * find_max_val - finds maximum value of array
 * @array: array where to get max value
 * @size: array size
 * Return: maximum value
 */
int find_max_val(int *array, size_t size)
{
	int maxi;
	size_t m;

	if (size < 2)
	{
		return (0);
	}
	maxi = array[0];
	for (m = 1; m < size; m++)
	{
		if (maxi < array[m])
			maxi = array[m];
	}
	return (maxi);
}

/**
 * counting_sort - a function that sorts an array of integers in
 * ascending order using the Counting sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int m = find_max_val(array, size), p, *pos, *sumpos, *sorti;
	size_t n;

	if (m == 0)
		return;
	pos = malloc(sizeof(int) * (m + 1));
	if (!pos)
		return;
	init_zero(pos, m + 1);

	for (n = 0; n < size; n++)
		pos[array[n]] += 1;

	sumpos = malloc(sizeof(int) * (m + 1));
	if (!sumpos)
		return;
	init_zero(sumpos, m + 1);
	sumpos[0] = pos[0];

	for (p = 1; p < (m + 1); p++)
		sumpos[p] = pos[p] + sumpos[p - 1];
	free(pos), print_array(sumpos, m + 1);
	sorti = malloc(sizeof(int) * size);
	if (!sorti)
		return;
	init_zero(sorti, size);
	for (n = 0; n < size; n++)
	{
		sumpos[array[n]] -= 1;
		sorti[sumpos[array[n]]] = array[n];
	}
	free(sumpos);
	for (n = 0; n < size; n++)
		array[n] = sorti[n];
	free(sorti);
}
