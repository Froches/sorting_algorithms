#include "sort.h"

/**
 * insertion_sort_list - Implementing the insertion sort algorithm
 * @list: The list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *temp;

	if (*list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		temp = current;
		prev = current->prev;

		while (prev && prev->n > temp->n)
		{
			if (temp->next)
				temp->next->prev = prev;
			prev->next = temp->next;
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;

			if (temp->prev)
				temp->prev->next = temp;
			else
				*list = temp;

			prev = temp->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
