#include "sort.h"

/**
 * swap_int - a function to swap integers
 * @a: integer a
 * @b: integer b
 **/
void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * max_heap - The main function to heapify a Max Heap. The function
 * assumes that everything under given root (element at index idx)
 * is already heapified
 * @array: array
 * @size: size of the array for print
 * @idx: index
 * @n: size of the array to run
 */
void max_heap(int *array, size_t size, int idx, size_t n)
{
	int largest = idx;
	int left = 2 * idx + 1;
	int right = 2 * idx + 2;

	if (left < (int)n && array[left] > array[largest])
		largest = left;

	if (right < (int)n && array[right] > array[largest])
		largest = right;

	if (largest != idx)
	{
		swap_int(&array[idx], &array[largest]);
		print_array(array, size);
		max_heap(array, size, largest, n);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == '\0' || size < 2)
		return;

	for (i = (size - 2) / 2; i >= 0; --i)
		max_heap(array, size, i, size);

	for (i = (size - 1); i > 0; --i)
	{
		swap_int(&array[0], &array[i]);
		print_array(array, size);
		max_heap(array, size, 0, i);
	}
}
