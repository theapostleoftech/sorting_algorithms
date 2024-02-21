#include "sort.h"
/**
* get_max - A utility function to get maximum value in arr[]
* @arr: array
* @n: size of the array
* Return: array
*/
int get_max(int *arr, int n)
{
	int i, max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

/**
* count_sort - A function to do counting sort of arr[] according to
* the digit represented by exp.
* @arr: array
* @n: size of the array
* @exp: exp is 10^i
* @output: array to save the temporary values
*/
void count_sort(int *arr, size_t n, int exp, int *output)
{
	int i;
	int count[10] = {0};

	for (i = 0; i < (int)n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < (int)n; i++)
		arr[i] = output[i];
}

/**
* radix_sort - The main function that sorts arr[]
* of size n using Radix Sort
* @array: array
* @size: size of the array
*/
void radix_sort(int *array, size_t size)
{
	int exp, max = 0;
	int *output = NULL;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		count_sort(array, size, exp, output);
		print_array(array, size);
	}
	free(output);
}
