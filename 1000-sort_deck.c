#include "deck.h"

/**
 * _strcmp - a function to compare two strings
 * @str_a: the first string
 * @str_b: the second string
 * Return: 1 or 0 not equal
 */
int _strcmp(const char *str_a, char *str_b)
{
	size_t i = 0;

	if (str_a == '\0')
		return (0);
	while (str_a[i])
	{
		if (str_a[i] != str_b[i])
			return (0);
		i++;
	}
	if (str_a[i] == '\0' && str_b[i])
		return (0);
	return (1);
}

/**
 * get_card_position - return the position based on card you put in
 * @node: represent the card
 * Return: return the card position
 */
int get_card_ps(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}

/**
 * swap_card - swap a card from the previous one
 * @card: card
 * @deck: card deck
 * Return: return a pointer to a card
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *curr = card;

	back->next = curr->next;
	if (curr->next)
		curr->next->prev = back;
	curr->next = back;
	curr->prev = back->prev;
	back->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*deck = curr;
	return (curr);
}

/**
 * insertion_sort_deck - function that sorts a doubly linked deck
 * of integers in ascending order using the Insertion sort algorithm
 * @deck: Dobule linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	int value_prev, value_curr;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		if (node->prev)
		{
			value_prev = get_card_ps((node->prev));
			value_curr = get_card_ps(node);
		}
		while ((node->prev) && (value_prev > value_curr))
		{
			value_prev = get_card_ps((node->prev));
			value_curr = get_card_ps(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - sort a deck using
 * insertion sort algorithm
 * @deck: deck to be sorted
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort_deck(deck);
}

