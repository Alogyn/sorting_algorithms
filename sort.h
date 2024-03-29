#ifndef SORT_H
#define SORT_H

/* Standard Libreries */
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

/**
  * struct listint_s - Doubly linked list node
  *
  * @n: Integer stored in the node
  * @prev: Pointer to the previous element of the list
  * @next: Pointer to the next element of the list
  */

typedef struct listint_s
{	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print functions */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Task 0. Bubble sort */
void bubble_sort(int *array, size_t size);

/* Task 1. Insertion sort */
void insertion_sort_list(listint_t **list);

/* Task 2. Selection sort */
void selection_sort(int *array, size_t size);

/* Task 3. Quick sort */
void quick_sort(int *array, size_t size);
void quick_sort_recursive(int *array, size_t low, size_t high, size_t size);
int lomuto_partition(int *array, size_t low, size_t high, size_t size);
void swap_items(int *array, size_t l, size_t r);

/* Task 4. Shell sort - Knuth Sequence (Advanced) */
void shell_sort(int *array, size_t size);

/* Task 5. Cocktail shaker sort (Advanced) */
void cocktail_sort_list(listint_t **list);
void swap_nodes(listint_t **node, listint_t **list);

/* Task 6. Counting sort (Advanced) */
void counting_sort(int *array, size_t size);

/* Task 7. Merge sort (Advanced) */
void copy(int *src, int *dst, int size);
void merge(int *array, int *buff, int minL, int maxL, int minR, int maxR);
void printcheck(int *array, int r1, int r2);
void split(int *array, int *buff, int min, int max, int size);
void merge_sort(int *array, size_t size);

/* Task 8. Heap sort (Advanced) */
void heap_sort(int *array, size_t size);
void check_tree(int *array, size_t size_init, size_t size, size_t i);

/* Task 9. Radix sort (Advanced) */
void radix_sort(int *array, size_t size);
int getMax(int *array, size_t size);
void countingSort(int *array, size_t size, int exp);

/* Task 10. Bitonic sort (Advanced) */
void bitonic_sort(int *array, size_t size);
void swap(int arr[], int item1, int item2, int order);
void merges(int arr[], int low, int nelement, int order);
void bitonicsort(int arr[], int low, int nelement, int order, int size);

/* Task 11. Quick Sort - Hoare Partition scheme (Advanced) */
void quick_sort_hoare(int *array, size_t size);
void swapss(int *array, ssize_t item1, ssize_t item2);
int hoare_partition(int *array, int first, int last, int size);
void qs(int *array, ssize_t first, ssize_t last, int size);

#endif /* SORT_H */
