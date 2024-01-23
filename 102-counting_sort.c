#include "sort.h"

/* Task 6. Counting sort (Advanced) */

/**
	* counting_sort - Sorts an array of integers in ascending order
	* using the Counting sort algorithm
	*
	* @array: The array to be sorted
	* @size: The size of the array
	*
	* Return: None
	*/

void counting_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/* Find the maximum value in the array */
	int max = array[0];
	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create a counting array of size max+1 and initialize to zero */
	int *count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	for (int i = 0; i <= max; i++)
		count[i] = 0;

	/* Count occurrences of each element in the input array */
	for (size_t i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	print_array(count, max + 1);

	/* Update the input array with sorted values */
	size_t j = 0;
	for (int i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[j] = i;
			j++;
			count[i]--;
		}
	}

	/* Free the counting array */
	free(count);
}
