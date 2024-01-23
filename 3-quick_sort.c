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
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}

/**
  * quick_sort_recursive - Recursive function for quick sort
  * @array: The array to be sorted
  *
  * @low: The starting index of the partition to be sorted
  * @high: The ending index of the partition to be sorted
  * @size: Number of elements in the array
  *
  * Return: None
  */

void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int partition_index;

	if (low < high)
	{
		partition_index = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, partition_index - 1, size);
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
	int pivot, temp;
	int i, j;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}

	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);

	return (i + 1);
}
