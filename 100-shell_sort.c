#include "sort.h"

/**
* swap_element - a function to swap the positions of two elements
* @array: the array to be swapped
* @element_a: the first element in the array
* @element_b: the first element in the array
*/
void swap_element(int *array, int element_a, int element_b)
{

	int temp;

	temp = array[element_a];
	array[element_a] = array[element_b];
	array[element_b] = temp;
}
/**
 * shell_sort - a function that sorts an array of integers in ascending
 * order using the Shell sort algorithm, using the Knuth sequence
 * @array: the array list with numbers
 * @size: the size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1, i, idx = 0;

	if (array == NULL || size < 2)
		return;
	while (n < size / 3)
		n = 3 * n + 1;
	while (n >= 1)
	{
		for (i = n; i < size; i++)
			for (idx = i; idx >= n &&
			 (array[idx] < array[idx - n]); idx -= n)
				swap_element(array, idx, idx - n);
		print_array(array, size);
		n /= 3;
	}
}
