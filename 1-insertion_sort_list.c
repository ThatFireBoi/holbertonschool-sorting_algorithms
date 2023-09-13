#include "sort.h"

/**
 * insertion_sort_list - Sort doubly linked list of integers in ascending order
 * @list: A pointer to the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion_point;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		insertion_point = current->prev;

		while (insertion_point != NULL && insertion_point->n > current->n)
		{
			if (current->next != NULL)
				current->next->prev = insertion_point;

			insertion_point->next = current->next;
			current->prev = insertion_point->prev;
			insertion_point->prev = current;
			current->next = insertion_point;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			print_list(*list);  /* Print the list after each swap */

			insertion_point = current->prev;
		}

		current = current->next;
	}
}
