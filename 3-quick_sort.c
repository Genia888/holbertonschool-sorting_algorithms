#include "sort.h"
#include <stddef.h>

/**
 * lomuto_partition - Scanning an array with lomuto partition scheme.
 * @array: The array to be sorted.
 * @low: The low index.
 * @high: The high index.
 * @size: The size of the array.
 *
 * Return: The index pivot.
 */

int	lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j = low;

	while (j < high)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				int temp = array[i];

				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
		j++;
	}
	if (array[i + 1] != array[high])
	{
		int temp = array[i + 1];

		array[i + 1] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Sort an array in ascending order.
 * @array: The array.
 * @low: The lowest index of the partition to sort.
 * @high: The highest index of the partition to sort.
 * @size: Number of elements in the array.
 */

void	quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quick_sort_recursive(array, low, pivot - 1, size);
		quick_sort_recursive(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - Sort an array in ascending order.
 * @array: The array.
 * @size: Number of elements in the array.
 */

void	quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_recursive(array, 0, size - 1, size);
}
