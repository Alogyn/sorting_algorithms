#include "sort.h"

/* Task 3. Quick sort */

/**
  * quick_sort - Sorts an array of integers in ascending order using
  * the Quick sort algorithm with Lomuto partition scheme
  *
  * @array: The array to be sorted
  * @size: Number of elements in the array
  *
  * Return: None
  */

void quick_sort(int *array, size_t size)
{
	if (array != NULL)
		quick_sort_recursive(array, 0, size - 1, size);
}

/**
  * quick_sort_recursive - Recursive function for quick sort
  *
  * @array: The array to be sorted
  * @low: The starting index of the partition to be sorted
  * @high: The ending index of the partition to be sorted
  * @size: Number of elements in the array
  *
  * Return: None
  */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	size_t partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		if (partition_index > 0)
			quick_sort_recursive(array, low, partition_index - 1, size);
		if (partition_index < high)
			quick_sort_recursive(array, partition_index + 1, high, size);
	}
}

/**
  * lomuto_partition - Lomuto partition scheme for quick sort
  *
  * @array: The array to be partitioned
  * @low: The starting index of the partition
  * @high: The ending index of the partition
  * @size: Number of elements in the array
  *
  * Return: The index of the pivot element after partitioning
  */

int lomuto_partition(int *array, int low, int high, size_t size)
{
	size_t k, i;
	int pivot;

	if ((low >= high) || (array == NULL))
		return (high);

	pivot = array[high];
	k = low;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (k != i)
			{
				swap_items(array, k, i);
				print_array(array, size);
			}
			k++;
		}
	}

	if (k != high)
	{
		swap_items(array, k, high);
		print_array(array, size);
	}

	return (k);
}

/**
  * swap_items - Swaps two items in an array
  *
  * @array: The array to modify
  * @l: The index of the left item
  * @r: The index of the right item
  *
  * Return: None
  */

void swap_items(int *array, size_t l, size_t r)
{
	int tmp;

	if (array != NULL)
	{
		tmp = array[l];
		array[l] = array[r];
		array[r] = tmp;
	}
}
