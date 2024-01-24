#include "sort.h"

/* Task 10. Bitonic sort (Advanced) */

/**
  * swap - Swap two values in ascending or descending order
  *
  * @arr: The array
  * @item1: Index of the first item
  * @item2: Index of the second item
  * @order: 1 for ascending order, 0 for descending order
  *
  * Return: None
  */

void swap(int arr[], int item1, int item2, int order)
{
	int temp;

	if (order == (arr[item1] > arr[item2]))
	{
		temp = arr[item1];
		arr[item1] = arr[item2];
		arr[item2] = temp;
	}
}

/**
  * merge - Recursively sort bitonic sequences in both orders
  *
  * @arr: The array
  * @low: Index of the first element
  * @nelement: Number of elements in the sequence
  * @order: 1 for ascending order, 0 for descending order
  *
  * Return: None
  */

void merge(int arr[], int low, int nelement, int order)
{
	int mid, i;

	if (nelement > 1)
	{
		mid = nelement / 2;
		for (i = low; i < low + mid; i++)
			swap(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}

/**
  * bitonicsort - Bitonic sort algorithm implementation
  *
  * @arr: The array
  * @low: Index of the first element
  * @nelement: Number of elements in the sequence
  * @order: 1 for ascending order, 0 for descending order
  * @size: Total size of the array
  *
  * Return: None
  */

void bitonicsort(int arr[], int low, int nelement, int order, int size)
{
	int mid;

	if (nelement > 1)
	{
		if (order >= 1)
			printf("Merging [%i/%i] (UP):\n", nelement, size);
		else
			printf("Merging [%i/%i] (DOWN):\n", nelement, size);

		print_array(&arr[low], nelement);

		mid = nelement / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, nelement, order);

		if (order <= 0)
			printf("Result [%i/%i] (DOWN):\n", nelement, size);
		else
			printf("Result [%i/%i] (UP):\n", nelement, size);

		print_array(&arr[low], nelement);
	}
}

/**
  * bitonic_sort - Prepare the terrain for the bitonic sort algorithm
  *
  * @array: The array
  * @size: Total size of the array
  *
  * Return: None
  */

void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;

	bitonicsort(array, 0, size, order, size);
}
