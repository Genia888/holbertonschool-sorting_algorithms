#include "deck.h"
#include <string.h>

/**
 * get_card_value - Get integer value of a card string
 * @value: String value of card (e.g., "Ace", "2", "Jack")
 * Return: Integer from 0 to 12
 */
int get_card_value(const char *value)
{
	const char *values[] = {"Ace", "2", "3", "4", "5", "6", "7",
				"8", "9", "10", "Jack", "Queen", "King"};
	int i;

	for (i = 0; i < 13; i++)
	{
		if (strcmp(value, values[i]) == 0)
			return (i);
	}
	return (-1);
}

/**
 * compare_cards - Compare two cards
 * @a: First card node
 * @b: Second card node
 * Return: Negative if a < b, 0 if equal, positive if a > b
 */
int compare_cards(const deck_node_t *a, const deck_node_t *b)
{
	if (a->card->kind != b->card->kind)
		return (a->card->kind - b->card->kind);
	return (get_card_value(a->card->value) - get_card_value(b->card->value));
}

/**
 * swap_nodes - Swap two adjacent nodes in the list
 * @deck: Pointer to deck head
 * @a: First node
 * @b: Second node
 */
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*deck = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * sort_deck - Sorts a 52-card deck
 * @deck: Pointer to deck head
 */
void sort_deck(deck_node_t **deck)
{
	deck_node_t *node;
	int sorted = 0;

	if (!deck || !*deck || !(*deck)->next)
		return;

	while (!sorted)
	{
		sorted = 1;
		node = *deck;
		while (node->next)
		{
			if (compare_cards(node, node->next) > 0)
			{
				swap_nodes(deck, node, node->next);
				sorted = 0;
			}
			else
				node = node->next;
		}
	}
}
