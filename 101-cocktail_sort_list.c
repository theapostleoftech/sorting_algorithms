#include "sort.h"
/**
 * swap_node - a function that swaps a node
 * @node: node to be swapped
 * @list: the node list
 *
 * Return: the pointer to the node
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *end = node->prev, *curr = node;

	end->next = curr->next;
	if (curr->next)
		curr->next->prev = end;
	curr->next = end;
	curr->prev = end->prev;
	end->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}


/**
 * cocktail_sort_list - this is a cocktail sort implementation that works
 * on a doubly linked list
 * @list: the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swap_node(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swap_node(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
