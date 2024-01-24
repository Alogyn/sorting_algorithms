#include "sort.h"

/* Task 10. Bitonic sort (Advanced) */

/**
  * bitonic_compare - Compares and swaps two elements based on the order
  *
  * @array: The array of integers
  * @size: The size of the array
  * @i: Index of the first element
  * @j: Index of the second element
  * @order: Sorting order (1 for ascending, 0 for descending)
  *
  * Return: None
  */

void bitonic_compare(int *array, size_t size, size_t i, size_t j, int order)
{
	int tmp;

	if ((array[i] > array[j] && order) || (array[i] < array[j] && !order))
	{
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;

		printf("Merging [%lu/%lu] (%s):\n", size, size, (order) ? "UP" : "DOWN");
		print_array(array, size);
	}
}

/**
  * bitonic_merge - Merges two bitonic sequences
  *
  * @array: The array of integers
  * @size: The size of the array
  * @start: Starting index of the sequence
  * @order: Sorting order (1 for ascending, 0 for descending)
  *
  * Return: None
  */

void bitonic_merge(int *array, size_t size, size_t start, int order)
{
	size_t i, k;

	if (size > 1)
	{
		k = size / 2;
		for (i = start; i < start + k; i++)
			bitonic_compare(array, size, i, i + k, order);

		bitonic_merge(array, k, start, order);
		bitonic_merge(array, k, start + k, order);
	}
}

/**
  * bitonic_sort_recursive - Recursively applies bitonic sort
  *
  * @array: The array of integers
  * @size: The size of the array
  * @order: Sorting order (1 for ascending, 0 for descending)
  *
  * Return: None
  */

void bitonic_sort_recursive(int *array, size_t size, int order)
{
	size_t k;

	if (size > 1)
	{
		k = size / 2;
		bitonic_sort_recursive(array, k, 1);
		bitonic_sort_recursive(array + k, k, 0);

		bitonic_merge(array, size, 0, order);
	}
}

/**
  * bitonic_sort - Sorts an array of integers in ascending order
  * using the Bitonic sort algorithm
  *
  * @array: The array of integers
  * @size: The size of the array (must be a power of 2)
  *
  * Return: None
  */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_sort_recursive(array, size, 1);
}
