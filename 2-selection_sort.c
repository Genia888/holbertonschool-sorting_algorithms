#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * selection_sort - fonction that sort of integers in ascending order
 * @array : the array
 * @size : the size of array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, x;
	int n, small;

	for (i = 0; i < size ; i++)
	{
		n = array[i];
		for (x = i; x < size; x++)
		{
			if (n > array[x])
			{
				n = array[x];
				small = x;
			}
		}

		if (array[i] != n)
		{
			array[small] = array[i];
			array[i] = n;
			print_array(array, size);
		}
	}
}
