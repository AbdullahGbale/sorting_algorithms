#include <stdio.h>

/**
 * swap - Swap two integers.
 * @i: Pointer to the first integer to swap.
 * @j: Pointer to the second integer to swap.
 */
void swap(int *i, int *j)
{
	int temp;

	temp = *i;
	*i = *j;
	*j = temp;
}
/**
 * partition - Perform Lomuto partition for Quick Sort.
 * @array: Pointer to the array to be partitioned.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Number of elements in the array.
 *
 * Return: Index of the pivot element after partition.
 */
int partition(int *array, size_t size, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (i + 1 != high)
		print_array(array, size);

	return (i + 1);
}
/**
 * lomuto_sort - function to implement Quick Sort.
 * @array: Pointer to the array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 * @size: Number of elements in the array.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(array, size, low, high);

		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}
/**
 * quick_sort - Sorts an array of integers in ascending order using
 * the Quick sort algorithm with the Lomuto partition scheme.
 * @array: Pointer to the array to be sorted.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
