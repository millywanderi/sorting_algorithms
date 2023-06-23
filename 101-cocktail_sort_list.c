#include "sort.h"

/**
 * swap_node - swapping the list nodes
 * @list: doubly linked list node
 * @one: first node address
 * @two: second node address
 */
void swap_node(listint_t **list, listint_t *one, listint_t *two)
{
	if (!one->prev)
		*list = two;
	else
		one->prev->next = two;
	two->prev = one->prev;
	if (two->next)
		two->next->prev = one;
	one->prev = two;
	one->next = two->next;
	two->next = one;
}

/**
 * cocktail_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list node
 */
void cocktail_sort_list(listint_t **list)
{
	int swapp = 1;
	listint_t *fut;

	if (!list || !(*list) || !(*list)->next)
		return;
	fut = *list;
	while (swapp)
	{
		swapp = 0;
		while (fut->next)
		{
			if (fut->n > fut->next->n)
			{
				swap_node(list, fut, fut->next);
				print_list(*list);
				swapp = 1;
				continue;
			}
			fut = fut->next;
		}
		if (!swapp)
			break;
		swapp = 0;
		while (fut->prev)
		{
			if (fut->n < fut->prev->n)
			{
				swap_node(list, fut->prev, fut);
				print_list(*list);
				swapp = 1;
				continue;
			}
			fut = fut->prev;
		}
	}
}
