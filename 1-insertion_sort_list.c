#include "sort.h"
#include <stddef.h>

/**
 * SortList
 * @pList: list to sort
 *
 * Return: List sort
 */
listint_t *SortList(listint_t *pList)
{
	listint_t *current;
	listint_t *head = NULL;

	if (pList == NULL || pList->next == NULL)
		return (pList);
	while (pList != NULL) 
	{
		print_list(head);
		current = pList;
		pList = pList->next;
		if (head == NULL || current->n < head->n)
		{
			current->next = head;
			head = current;
		} 
		else 
		{
			listint_t *p = head;
			while (p != NULL) {
				if (p->next == NULL || 
						current->n < p->next->n) 
				{
					current->next = p->next;
					p->next = current;
					break; 
				}
				p = p->next;
			}
		}
	}
	return head;
}
/** 
 * insertion_sort_list - tri in insert mode
 *@list : list chain
 */
void insertion_sort_list(listint_t **list)
{
	*list = SortList(*list);
}
