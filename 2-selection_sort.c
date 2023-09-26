#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */

void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - Sorts an array of integers in ascending order
 *                 using the Selection sort algorithm.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_index = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		if (min_index != i)
		{
			swap_ints(&array[i], &array[min_index]);
			for (j = 0; j < size; j++)
			{
				printf("%d", array[j]);
				if (j < size - 1)
					printf(", ");
			}
			printf("\n");
		}
	}
}
