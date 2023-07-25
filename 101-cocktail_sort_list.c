#include "sort.h"
#include <stdio.h>
/**
 *cocktail_sort_list - sorts a doubly linked list with cocktail sort
 *
 *@list: The doubly linked list
 *Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	bool swapped = true;
	listint_t *pointer = *list;

	if (!list || !*list)
		return;
	while (swapped)
	{
		swapped = false;
		while (pointer->next)
		{
			if (pointer->n > pointer->next->n)
			{
				if (!pointer->prev)
					*list = pointer->next;
				swap_node(*list, pointer, pointer->next);
				swapped = true;
				continue;
			}
			pointer = pointer->next;
		}
		if (!swapped)
			return;
		pointer = pointer->prev;
		while (pointer)
		{
			if (pointer->n > pointer->next->n)
			{
				if (!pointer->prev)
					*list = pointer->next;
				swap_node(*list, pointer, pointer->next);
				swapped = true;
				pointer = pointer->prev;
				if (!pointer->prev)
					break;
			}
			if (!pointer->prev)
				return;
			pointer = pointer->prev;
		}
	}
}

/**
 *eject_node - Ejects a node from its current position
 *
 *@node: The current node being ejected
 *Return: void
 */
void eject_node(listint_t *node)
{
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
}
/**
 *swap_node - Swaps two nodes in a doubly linked list
 *@node_1: The first node
 *@node_2: The second node
 *@list: The doubly linked list being edited
 *Return: void
 */
void swap_node(listint_t *list, listint_t *node_1, listint_t *node_2)
{
	eject_node(node_1);
	if (node_2->next)
		node_2->next->prev = node_1;
	node_1->next = node_2->next;
	node_1->prev = node_2;
	node_2->next = node_1;
	print_list(list);
}
