#include "sort.h"
/**
* swap_elements - a function to swap the position
* of two elements in an array
* @array: array
* @element_a: the first element
* @element_b: the second element
*/
void swap(int *array, ssize_t element_a, ssize_t element_b)
{
	int temp;

	temp = array[element_a];
	array[element_a] = array[element_b];
	array[element_b] = temp;
}

/**
 * hoare_partition - hoare partition sorting scheme implementation
 * @array: array
 * @first: the first eleemnt of the array
 * @last: the last element of the array
 * @size: the size of the array
 * Return: return the position of the last element sorted
 */
int hoare_partition(int *array, int first, int last, int size)
{
	int curr = first - 1, key = last + 1;
	int pivot = array[last];

	while (1)
	{

		do {
			curr++;
		} while (array[curr] < pivot);
		do {
			key--;
		} while (array[key] > pivot);
		if (curr >= key)
			return (curr);
		swap(array, curr, key);
		print_array(array, size);
	}
}
/**
 * q_sort - qucksort algorithm implementation
 * @array: array
 * @first: first array element
 * @last: last array element
 * @size: array size
 */
void q_sort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t ps = 0;

	if (first < last)
	{
		ps = hoare_partition(array, first, last, size);
		q_sort(array, first, ps - 1, size);
		q_sort(array, ps, last, size);
	}
}
/**
 * quick_sort_hoare - prepare the terrain to quicksort algorithm
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	q_sort(array, 0, size - 1, size);
}
