#include "sort.h"

/**
 * swap_nodes - Swap 2 nodes in doubly-linked list
 * @head: ptr to head of doubly-linked list
 * @node_1: ptr to first node to be swapped
 * @node_2: sec node to be swapped
 */
void swap_nodes(listint_t **head, listint_t **node_1, listint_t *node_2)
{
	(*node_1)->next = node_2->next;
	if (node_2->next != NULL)
		node_2->next->prev = *node_1;
	node_2->prev = (*node_1)->prev;
	node_2->next = *node_1;
	if ((*node_1)->prev != NULL)
		(*node_1)->prev->next = node_2;
	else
		*head = node_2;
	(*node_1)->prev = node_2;
	*node_1 = node_2->prev;
}

/**
 * insertion_sort_list - Sort doubly-linked list
 * @list: ptr to head of doubly-linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *repe, *insert, *temp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (repe = (*list)->next; repe != NULL; repe = temp)
	{
		temp = repe->next;
		insert = repe->prev;
		while (insert != NULL && repe->n < insert->n)
		{
			swap_nodes(list, &insert, repe);
			print_list((const listint_t *)*list);
		}
	}
}
