#ifndef DECK_H
#define DECK_H

#include <string.h>
#include <stdio.h>
#include "sort.h"
#include <stdlib.h>

/**
 * enum kind_e - enumeration of card suits
 * @SPADE: spade suit = 0
 * @HEART: hear suit = 1
 * @CLUB: club suit = 2
 * @DIAMOND: diamond suit = 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_nod_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

void sort_suit(deck_node_t **l, deck_node_t *cur, deck_node_t *end, int dire);
deck_node_t *rec(deck_node_t **l, deck_node_t *cur, deck_node_t *end, int dire);
int rankt(const char *rank_str);
void dnodes_swap(deck_node_t **list, deck_node_t **m, deck_node_t **n, int *k);
void sort_deck(deck_node_t **deck);

#endif
