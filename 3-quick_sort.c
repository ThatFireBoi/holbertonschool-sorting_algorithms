#include "sort.h"

/**
 * lomuto_partition - Lomuto partition scheme for Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The low index of the partition
 * @high: The high index of the partition
 * Return: The pivot index
 */
size_t lomuto_partition(int *array, size_t size, ssize_t low, ssize_t high)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
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
 * quicksort_recursive - Recursive function to perform quicksort
 * @array: The array to be sorted
 * @size: The size of the array
 * @low: The low index of the partition
 * @high: The high index of the partition
 */
void quicksort_recursive(int *array, size_t size, ssize_t low, ssize_t high)
{
	if (low < high)
	{
		size_t pivot_index = lomuto_partition(array, size, low, high);

		quicksort_recursive(array, size, low, pivot_index - 1);
		quicksort_recursive(array, size, pivot_index + 1, high);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick Sort
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size <= 1)
		return;

	quicksort_recursive(array, size, 0, size - 1);
}
