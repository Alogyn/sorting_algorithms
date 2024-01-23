#include "sort.h"

/* Task 9. Radix sort (Advanced) */

/**
  * getMax - Returns the maximum element from an array
  *
  * @array: The array of integers
  * @size: The size of the array
  *
  * Return: The maximum element
  */

int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
  * countingSort - Performs counting sort based on significant place
  *
  * @array: The array of integers
  * @size: The size of the array
  * @exp: The current significant place (1, 10, 100, ...)
  *
  * Return: None
  */

void countingSort(int *array, size_t size, int exp)
{
	int *output = NULL;
	int count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	/* Count occurrences of digits at the current significant place */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Update count[i] to store the position of the next occurrence */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build the output array */
	for (i = size - 1; i < size; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	/* Copy the output array to the original array */
	for (i = 0; i < size; i++)
		array[i] = output[i];

	print_array(array, size);

	free(output);
}

/**
  * radix_sort - Sorts an array of integers in ascending order
  * using the Radix sort algorithm (LSD)
  *
  * @array: The array of integers
  * @size: The size of the array
  *
  * Return: None
  */

void radix_sort(int *array, size_t size)
{
	int max, exp;

	if (!array || size < 2)
		return;

	max = getMax(array, size);

	/* Perform counting sort for every digit place */
	for (exp = 1; max / exp > 0; exp *= 10)
		countingSort(array, size, exp);
}
