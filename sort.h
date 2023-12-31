#ifndef SORT_H
#define SORT_H
#include <stddef.h>
#include <stdbool.h>
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void eject_node(listint_t *node);
void quickSort(int *array, size_t size, int lo, int hi);
int partition(int *array, size_t size, int lo, int hi);
void swap(int *array, size_t size, int i, int j);
void swap_node(listint_t *list, listint_t *node_1, listint_t *node_2);
void shell_sort(int *array, size_t size);
size_t max_gap(size_t size);
void cocktail_sort_list(listint_t **list);

#endif /* SORT_H */
