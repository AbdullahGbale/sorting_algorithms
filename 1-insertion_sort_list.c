#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 * the Insertion sort algorithm.
 * @list: A pointer to a pointer to the head of the linked list.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current = *list;
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		next = current->next;
		current->prev = sorted;
		current->next = NULL;

		if (sorted == NULL || sorted->n >= current->n)
		{
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			listint_t *tmp = sorted;

			while (tmp->next != NULL && tmp->next->n < current->n)
				tmp = tmp->next;
			current->next = tmp->next;
			if (tmp->next != NULL)
				tmp->next->prev = current;
			tmp->next = current;
			current->prev = tmp;
		}
		if (current->prev == NULL)
			*list = current;
		else
			current->prev->next = current;
		print_list(*list);
		current = next;
	}
}
