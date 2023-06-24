#include "sort.h"
/**
 * zero_init - array initialization by 0
 * @array: array to undergo initialization
 * @size: array size
 */
void zero_init(int *array, int size)
{
	int m;

	for (m = 0; m < size; m++)
	{
		array[m] = 0;
	}
}

/**
 * max_dig - finds largest array element
 * @array: array to be sorted
 * @size: array size
 * Return: maximum element
 */

int max_dig(int *array, size_t size)
{
	size_t m;
	int maxi;

	maxi = array[0];
	for (m = 1; m < size; m++)
	{
		if (maxi < array[m])
		{
			maxi = array[m];
		}
	}
	return (maxi);
}

/**
 * count_sort - sorts the array
 * @array: array to be sorted
 * @size: array size
 * @loc: LSD position
 */
void count_sort(int *array, size_t size, int loc)
{
	int m, *pos, *sumpos, *sorti;
	size_t a, b;

	pos = malloc(sizeof(int) * 10);
	if (!pos)
		return;
	zero_init(pos, 10);
	for (a = 0; a < size; a++)
		pos[(array[a] / loc) % 10] += 1;
	sumpos = malloc(sizeof(int) * 10);
	if (!sumpos)
		return;
	zero_init(sumpos, 10);
	sumpos[0] = pos[0];

	for (b = 1; b < 10; b++)
		sumpos[b] = pos[b] + sumpos[b - 1];
	free(pos);

	sorti = malloc(sizeof(int) * size);
	if (!sorti)
		return;
	zero_init(sorti, size);
	for (m = size - 1; m >= 0; m--)
	{
		sumpos[(array[m] / loc) % 10] -= 1;
		sorti[sumpos[(array[m] / loc) % 10]] = array[m];
	}
	free(sumpos);
	for (a = 0; a < size; a++)
		array[a] = sorti[a];
	free(sorti);
}


/**
 * radix_sort - a function that sorts an array of integers in ascending
 * order using the Radix sort algorithm
 * @array: array to be sorted
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int pos = 1, maxi;

	if (!array || size < 2)
		return;
	maxi = max_dig(array, size);
	while ((maxi / pos) > 0)
	{
		count_sort(array, size, pos);
		print_array(array, size);
		pos *= 10;
	}
}
