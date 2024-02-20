i#include "sort.h"
/**
* swap_elements - a function that swaps elements in an array
* @array: the array to be swapped
* @element_a: elements in the array
* @element_b: elements in the array
*/
void swap_elements(int *array, ssize_t element_a, ssize_t element_b)
{
	int temp;

	temp = array[element_a];
	array[element_a] = array[element_b];
	array[element_b] = temp;
}


/**
 * lomuto_partition - lomuto partition sorting scheme implementation
 * @array: the array to be sorted
 * @first: the first element in the array
 * @last: the last element in the array
 * @size: the size of the array
 * Return: return the position of the last element sorted
 */
int lomuto_partition(int *array, ssize_t first, ssize_t last, size_t size)
{
	int pivot = array[last];
	ssize_t curr = first, key;

	for (key = first; key < last; key++)
	{
		if (array[key] < pivot)
		{
			if (array[curr] != array[key])
			{
				swap_elements(array, curr, key);
				print_array(array, size);
			}
			curr++;
		}
	}
	if (array[curr] != array[last])
	{
		swap_elements(array, curr, last);
		print_array(array, size);
	}
	return (curr);
}

/**
 * qsort - quicksort algorithm implementation
 * @array: the array to be sorted
 * @first: the first element in the array
 * @last: the last element in the array
 * @size: the size of the array
 */
void qsort(int *array, ssize_t first, ssize_t last, int size)
{
	ssize_t ps = 0;


	if (first < last)
	{
		ps = lomuto_partition(array, first, last, size);

		qsort(array, first, ps - 1, size);
		qsort(array, ps + 1, last, size);
	}
}

/**
 * quick_sort - a function that sorts an array of integers
 * in ascending order
 * @array: the array to be sorted
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	qs(array, 0, size - 1, size);
}

