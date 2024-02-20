#include "sort.h"
/**
 * insertion_sort_list - A function that sorts a doubly linked 
 * list in ascending order
 * @list: the doubly linked list to sort
 *
 * Return: void
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
 * swap_node -  function to swap a node
 * @node: the node to swap
 * @list: the node list
 *
 * Return: return the node swapped
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

