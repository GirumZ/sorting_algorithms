#include "sort.h"

void swap_nodes(listint_t **h, listint_t **node_1, listint_t **node_2);

/**
 * insertion_sort_list - sorts a list using insertion sort algotithm
 * @list: the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		previous = current->prev;
		while (previous != NULL)
		{
			if (previous->next->n < previous->n)
			{
				swap_nodes(list, &previous, &previous->next);
				print_list((*list));
			}
			previous = previous->prev;
		}
		current = current->next;
	}
}

void swap_nodes(listint_t **h, listint_t **node_1, listint_t **node_2)
{
	listint_t *n, *m;

	n = *node_1;
	m = *node_2;

	if (n->prev != NULL)
		n->prev->next = m;
	else
		*h = m;
	if (m->next != NULL)
		m->next->prev = n;
	n->next = m->next;
	m->next = n;
	m->prev = n->prev;
	n->prev = m;
	n = m->prev;
}
