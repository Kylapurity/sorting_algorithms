#include "sort.h"
#include <stdio.h>
/**
 *shell_sort - Sorts an array using the shell sort algorithm
 *
 *@array: An array of integers to be sorted.
 *@size: The size of the array
 *Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t j, k, i;
	int temp;

	if (!array || !size || !*array)
		return;

	i = max_gap(size);

	while (i)
	{
		for (j = i; j < size; j++)
		{
			temp = array[j];
			for (k = j; (k >= i) && (array[k - i] > temp); k -= i)
				array[k] = array[k - i];
			array[k] = temp;
		}
		print_array(array, size);
		i = (i - 1) / 3;
	}
}

/**
 *max_gap - gets the max range number
 *
 *@size: The size of the array being sorted
 *Return: the max integer
 */
size_t max_gap(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}
