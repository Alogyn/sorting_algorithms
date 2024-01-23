#ifndef SORT_H
#define SORT_H

/* Standard Libreries */
#include <stddef.h>
#include <stdio.h>

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
void swap_codes(listint_t **node, listint_t **list)

#endif /* SORT_H */
