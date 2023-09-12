#include "sort.h"

/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp;
	int swapped;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0; /* Initialize a flag to check for swaps */

		for (j = 0; j < size - i - 1; j++)
		{
			/* Compare adjacent elements and swap if necessary */
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;

				swapped = 1; /* Set the swap flag */
				print_array(array, size); /* Print the array after each swap */
			}
		}

		/* If no swaps were made in this pass, the array is sorted */
		if (swapped == 0)
			break;
	}
}
