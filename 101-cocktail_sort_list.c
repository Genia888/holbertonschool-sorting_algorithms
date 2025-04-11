#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Double pointer to the head
 * @a: First node
 * @b: Second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	else
		*list = b;

	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * forward_pass - Performs a left-to-right pass (forward cocktail pass)
 * @list: Double pointer to the head of the list
 * @start: Node to start the pass from
 * @end: Pointer to update with the last sorted node
 * Return: 1 if a swap occurred, 0 otherwise
 */
int forward_pass(listint_t **list, listint_t *start, listint_t **end)
{
	int swapped = 0;
	listint_t *current = start;

	while (current->next != *end)
	{
		if (current->n > current->next->n)
		{
			swap_nodes(list, current, current->next);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->next;
	}
	*end = current;
	return (swapped);
}

/**
 * backward_pass - Performs a right-to-left pass (backward cocktail pass)
 * @list: Double pointer to the head of the list
 * @start: Pointer to update with the new starting node
 * @end: Node to end the pass at
 * Return: 1 if a swap occurred, 0 otherwise
 */
int backward_pass(listint_t **list, listint_t **start, listint_t *end)
{
	int swapped = 0;
	listint_t *current = end;

	while (current->prev != (*start)->prev)
	{
		if (current->n < current->prev->n)
		{
			swap_nodes(list, current->prev, current);
			swapped = 1;
			print_list(*list);
		}
		else
			current = current->prev;
	}
	*start = current->next;
	return (swapped);
}

/**
 * cocktail_sort_list - Sorts a doubly linked list using Cocktail Shaker Sort
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *start, *end;
	int swapped;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	end = NULL;

	do {
		swapped = forward_pass(list, start, &end);
		if (!swapped)
			break;
		swapped = backward_pass(list, &start, end);
	} while (swapped);
}
