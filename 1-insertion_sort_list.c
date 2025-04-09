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
  if (!pList || !pList->next)
      return pList;

  /* build up the sorted array from the empty list */
  listint_t * pSorted = NULL;

  /* take items off the input list one by one until empty */
  while (pList != NULL) {
      /* remember the head */
      listint_t *  pHead  = pList;
      /* trailing pointer for efficient splice */
       listint_t ** ppTrail = &pSorted;

      /* pop head off list */
      pList = pList->next;

      /* splice head into sorted list at proper place */
      while (!(*ppTrail == NULL || pHead->n < (*ppTrail)->n)) { /* does head belong here? */
          /* no - continue down the list */
          ppTrail = &(*ppTrail)->next;
      }

      pHead->next = *ppTrail;
      *ppTrail = pHead;
  }

  return pSorted;
}
/** 
 * insertion_sort_list - tri in insert mode
 *@list : list chain
 */
void insertion_sort_list(listint_t **list)
{
	*list = SortList(*list);
}
