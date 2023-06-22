#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *curr;

	if (!list)
	{
		return;
	}
	for (curr = *list; curr; curr = curr->next)
	{
		while (curr->next && (curr->next->n < curr->n))
		{
			tmp = curr->next;
			curr->next = tmp->next;
			tmp->prev = curr->prev;

			if (curr->prev)
			{
				curr->prev->next = tmp;
			}
			if (tmp->next)
				tmp->next->prev = curr;
			curr->prev = tmp;
			tmp->next = curr;

			if (tmp->prev)
				curr = tmp->prev;
			else
				*list = tmp;
			print_list(*list);
		}
	}
}
