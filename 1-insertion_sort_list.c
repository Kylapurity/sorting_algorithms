#include "sort.h"
#include <stdio.h>
/**
 *insertion_sort_list - Sorts a linked list using the insertion sort algorithm
 *
 *@list: The sorted linked list
 *Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *pointer, *curr, *head;

	if (!list || !(*list) || !(*list)->next)
		return;

	head = (*list)->next;
	while (head)
	{
		curr = head;
		pointer = head->prev;
		while (curr->n < pointer->n)
		{
			eject_node(curr);
			if (pointer->prev)
				pointer->prev->next = curr;
			curr->prev = pointer->prev;
			pointer->prev = curr;
			curr->next = pointer;
			pointer = curr->prev;
			if (!pointer)
			{
				*list = curr;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		head = head->next;
	}
}

/**
 *eject_node - removes a node from its position in a doubly linked list
 *
 *@node: The node
 */
void eject_node(listint_t *node)
{
	if (node->next)
		node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
}
