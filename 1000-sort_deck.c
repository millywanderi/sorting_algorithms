#include "deck.h"

/**
 * sort_suit -sort suit deck recursively using cocktail shaker scheme
 * @l: list to be sorted
 * @cur: current node
 * @end: last node to be sorted
 * @dire: parse direction
 */
void sort_suit(deck_node_t **l, deck_node_t *cur, deck_node_t *end, int dire)
{
	int swapp = 0;
	deck_node_t *tmp = NULL, *next_end = NULL;

	if (end != NULL)
		next_end = cur;
	if (dire == 1)
	{
		do {
			if (cur->card->kind > cur->next->card->kind)
			{
				tmp = cur->next;
				dnodes_swap(&(*l), &cur, &tmp, &swapp);
			}
			cur = cur->next;
		} while (cur->next != end);
		if (swapp)
			sort_suit(&(*l), cur->prev, next_end, -1);
	}
	else
	{
		while (cur->prev != end)
		{
			if (cur->card->kind < cur->prev->card->kind)
			{
				tmp = cur->prev;
				dnodes_swap(&(*l), &tmp, &cur, &swapp);
			}
			cur = cur->prev;
		}
		if (swapp)
			sort_suit(&(*l), cur->next, next_end, 1);
	}
}

/**
 * rec - sort deck recurssively
 * @l: list to be sorted
 * @cur: current node
 * @end: last node
 * @dire: parse direction
 * Return: next suit pointer
 */
deck_node_t *rec(deck_node_t **l, deck_node_t *cur, deck_node_t *end, int dire)
{
	deck_node_t *tmp = NULL, *next_end = NULL, *next_suit = NULL;
	int swapp = 0;

	if (end != NULL)
		next_end = cur;

	if (dire == 1)
	{
		do {
			if (rankt(cur->card->value) > rankt(cur->next->card->value))
			{
				tmp = cur->next;
				dnodes_swap(&(*l), &cur, &tmp, &swapp);
			}
			cur = cur->next;
		} while (cur->next != end && cur->card->kind == cur->next->card->kind);
		if (swapp)
			rec(&(*l), cur->prev, next_end, -1);
		if (cur->next)
			if (cur->card->kind != cur->next->card->kind)
				next_suit = cur->next;
	}
	else
	{
		while (cur->prev != end && cur->card->kind == cur->prev->card->kind)
		{
			if (rankt(cur->card->value) < rankt(cur->prev->card->value))
			{
				tmp = cur->prev;
				dnodes_swap(&(*l), &tmp, &cur, &swapp);
			}
			cur = cur->prev;
		}
		if (swapp)
			rec(&(*l), cur->next, next_end, 1);
	}
	return (next_suit);
}

/**
 * rankt - convert str to int
 * @rank_str: string to be converted to int
 * Return: integer
 */
int rankt(const char *rank_str)
{
	int ran_int;

	if (!rank_str)
		return (-1);
	if (strcmp(rank_str, "Ace") == 0)
		ran_int = 1;
	else if (strcmp(rank_str, "Jack") == 0)
		ran_int = 11;
	else if (strcmp(rank_str, "Queen") == 0)
		ran_int = 12;
	else if (strcmp(rank_str, "King") == 0)
		ran_int = 13;
	else
	{
		ran_int = atoi(rank_str);
		if (ran_int < 1 || ran_int > 10)
			return (-1);
	}
	return (ran_int);
}

/**
 * dnodes_swap - swaps nodes
 * @list: list to be printed
 * @m: right node
 * @n: left node
 * @k: pointer calling swap funtion
 */
void dnodes_swap(deck_node_t **list, deck_node_t **m, deck_node_t **n, int *k)
{
	(*m)->next = (*n)->next;
	(*n)->prev = (*m)->prev;
	if ((*n)->next)
		(*n)->next->prev = (*m);
	if ((*m)->prev)
		(*m)->prev->next = (*n);
	(*n)->next = (*m);
	(*m)->prev = (*n);
	if (*m == *list)
		*list = *n;
	*k = 1;
}

/**
 * sort_deck - a function that sorts a deck of cards
 * @deck: deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *next_deck;

	if (!deck || !(*deck) || !(*deck)->next)
		return;

	sort_suit(deck, *deck, NULL, 1);
	next_deck = *deck;

	while (next_deck)
		next_deck = rec(deck, next_deck, NULL, 1);
}
