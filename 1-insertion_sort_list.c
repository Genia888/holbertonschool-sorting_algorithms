#include "sort.h"
#include <stddef.h>

/**
 * insertion_sort_list - tri in insert mode
 *@list : list chain
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *temp;

	if (list == NULL || (*list)->next == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		while (current->prev != NULL && current->n < current->prev->n)
		{
			temp = current->prev;
			temp->next = current->next;
			if (current->next != NULL)
				current->next->prev = temp;
			current->prev = temp->prev;
			current->next = temp;
			if (temp->prev != NULL)
				temp->prev->next = current;
			else
				*list = current;
			temp->prev = current;
			print_list(*list);
		}
		current = next;
	}
}
