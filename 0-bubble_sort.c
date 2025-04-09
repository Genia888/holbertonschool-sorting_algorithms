#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * bubble_sort - function that sorts an array of integers in ascending order
 * @array: the array
 * @size: the size of array
 * Return: always 0
 */

void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int temp;

	for (a = 0; a < size - 1 ; a++)
	{
		for (b = 0; b < size - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				temp = array[b + 1];
				array[b + 1] = array[b];
				array[b] = temp;
				print_array(array, size);
			}
		}

	}

}
