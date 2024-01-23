#include "sort.h"

/**
  * check_tree - Sift-down operation to maintain the max-heap property
  *
  * @array: Pointer to the array
  * @size_init: Original size of the array
  * @size: Current size of the heap
  * @i: Index representing the root of the tree
  *
  * Return: None
  */

void check_tree(int *array, size_t size_init, size_t size, size_t i)
{
	int n, branch1, branch2;
	size_t br1, br2;

	br1 = i * 2 + 1;
	br2 = br1 + 1;

	/* Retrieve values of left and right branches */
	branch1 = (br1 < size) ? array[br1] : array[i];
	branch2 = (br2 < size) ? array[br2] : array[i];

	/* Swap with the larger branch if necessary */
	if (((br1 < size) && (br2 < size) &&
		(branch1 >= branch2 && branch1 > array[i]))
		|| ((br1 == size - 1) && branch1 > array[i]))
	{
		n = array[i];
		array[i] = branch1;
		array[br1] = n;
		print_array(array, size_init);
	}
	else if ((br1 < size) && (br2 < size) &&
		(branch2 > branch1 && branch2 > array[i]))
	{
		n = array[i];
		array[i] = branch2;
		array[br2] = n;
		print_array(array, size_init);
	}

	/* Recursively check the left and right branches */
	if (br1 < size - 1)
		check_tree(array, size_init, size, br1);
	if (br2 < size - 1)
		check_tree(array, size_init, size, br2);
}

/**
  * heap_sort - Sorts an array of integers in ascending order
  * using the Heap sort algorithm
  *
  * @array: Pointer to the array
  * @size: Size of the array
  *
  * Return: None
  */
void heap_sort(int *array, size_t size)
{
	size_t i, size_init = size;
	int n;

	if (!array)
		return;

	/* Build max heap */
	for (i = size / 2; i > 0; i--)
		check_tree(array, size_init, size, i - 1);

	/* Extract elements from the heap one by one */
	for (i = 0; i < size_init - 1; i++)
	{
		n = array[0];
		array[0] = array[size - 1 - i];
		array[size - 1 - i] = n;
		print_array(array, size_init);
		check_tree(array, size_init, size - i - 1, 0);
	}
}
