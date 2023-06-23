#include "sort.h"

/**
 * printer - prints array value
 * @array: array which value to be printed from
 * @cont: values content
 * @lb: lower bound
 * @ub: upper bound
 */
void printer(int *array, const char *cont, size_t lb, size_t ub)
{
	size_t m;
	char *delim = "";

	printf("[%s]: ", cont);
	for (m = lb; m <= ub; m++)
	{
		printf("%s%d", delim, array[m]);
		delim = ", ";
	}
	printf("\n");
}

/**
 * join_print - join the printed value of an array
 * @array: array to be joined
 * @lb: lower bound
 * @ub: upper bound
 * @mb: midpoint of the bound
 * @cpy: stored value on an array
 */
void join_print(int *array, size_t lb, size_t ub, size_t mb, int *cpy)
{
	size_t hstat = mb + 1, idx, istat = lb, m;

	printf("Merging...\n");
	printer(array, "left", lb, mb);
	printer(array, "right", mb + 1, ub);

	for (idx = lb; idx <= ub; idx++)
	{
		if ((istat <= mb && array[istat] <= array[hstat]) || hstat > ub)
			cpy[idx] = array[istat++];
		cpy[idx] = array[hstat++];
	}
	for (m = lb; m <= ub; m++)
		array[m] = cpy[m];
	printer(array, "Done", lb, ub);
}

/**
 * pars - perform merge recursively
 * @array: array to be merged
 * @lb: lower bound
 * @ub: upper bound
 * @cpy: store sorted values in an array
 */
void pars(int *array, size_t lb, size_t ub, int *cpy)
{
	size_t mb;

	if (lb < ub)
	{
		mb = (ub + lb - 1) / 2;
		pars(array, lb, mb, cpy);
		pars(array, mb + 1, ub, cpy);
		join_print(array, lb, ub, mb, cpy);
	}
}

/**
 * merge_sort - a function that sorts an array of integers in
 * ascending order using the Merge sort algorithm
 * @array: array to be merged
 * @size: array size
 */
void merge_sort(int *array, size_t size)
{
	int *clon;

	if (!array || size < 2)
		return;
	clon = malloc(sizeof(int) * size);
	if (!clon)
		return;
	pars(array, 0, size - 1, clon);
	free(clon);
}
