#include "sort.h"
#include <stddef.h> 

/**
 * SortList
 * @pList: list to sort
 *
 * Return: List sort
 */
listint_t * SortList(listint_t * pList)
{

	// zero or one element in list
    if (pList == NULL || pList->next == NULL)
        return pList;
    // head is the first element of resulting sorted list
    listint_t *head = NULL;
    while (pList != NULL) {
        print_list(pList);
	listint_t * current = pList;
        pList = pList->next;
        if (head == NULL || current->n < head->n) {
            // insert into the head of the sorted list
            // or as the first element into an empty sorted list
            current->next = head;
            head = current;
        } else {
            // insert current element into proper position in non-empty sorted list
            listint_t *p = head;
            while (p != NULL) {
                if (p->next == NULL || // last element of the sorted list
                    current->n < p->next->n) // middle of the list
                {
                    // insert into middle of the sorted list or as the last element
                    current->next = p->next;
                    p->next = current;
                    break; // done
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
