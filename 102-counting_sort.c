#include "sort.h"
/**
 * counting_sort - a function to sort in ascending order using
 * the counting sort method
 * @array: the array to count
 * @size: the size of the array
 */
void counting_sort(int *array, size_t size)
{
	int idx, max_element = 0, *counter = '\0', *temp = '\0';
	size_t i;

	if (array == '\0' || size < 2)
		return;

	for (i = 0; i < size; i++)
		if (array[i] > max_element)
			max_element = array[i];
	counter = _calloc(max_element + 1, sizeof(int));
	temp = _calloc(size + 1, sizeof(int));

	for (i = 0; i < size; i++)
		counter[array[i]]++;

	for (idx = 1; idx <= max_element; idx++)
		counter[idx] += counter[idx - 1];
	print_array(counter, max_element + 1);

	for (i = 0; i < size; ++i)
	{
		temp[counter[array[i]] - 1] = array[i];
		counter[array[i]]--;
	}

	for (i = 0; i < size; i++)
		array[i] = temp[i];
	free(temp);
	free(counter);
}

