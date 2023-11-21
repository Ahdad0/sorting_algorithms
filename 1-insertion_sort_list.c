#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order
 *
 * @list: doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *tem;

	if (list == NULL)
		return;

	pointer = *list;

	while (pointer != NULL)
	{
		while (pointer->next != NULL && (pointer->n > pointer->next->n))
		{
			tem = pointer->next;
			pointer->next = tem->next;
			tem->prev = pointer->prev;

			if (pointer->prev != NULL)
			{
				pointer->prev->next = tem;
			}

			if (tem->next != NULL)
			{
				tem->next->prev = pointer;
			}

			pointer->prev = tem;
			tem->next = pointer;

			if (tem->prev != NULL)
			{
				pointer = tem->prev;
			}
			else
			{
				*list = tem;
			}
			print_list(*list);
		}
		pointer = pointer->next;
	}
}
