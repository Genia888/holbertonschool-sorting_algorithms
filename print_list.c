#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a doubly linked list of integers
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	while (list)
	{
		printf("%d", list->n);
		if (list->next)
			printf(", ");
		list = list->next;
	}
	printf("\n");
}
