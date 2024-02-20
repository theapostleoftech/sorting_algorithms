#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
 * swap_node - a function that swaps a node
 * @node: node to be swapped
 * @list: the node list
 * Return: nothing
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

