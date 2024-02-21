#include "sort.h"
/**
 * swap_e - change two values in ascending or descending order
 * @arr: array
 * @element_a: item one
 * @element_b: item two
 * @order: 1: ascending order, 0 descending order
 */
void swap_e(int arr[], int element_a, int element_b, int order)
{
	int temp;

	if (order == (arr[element_a] > arr[element_b]))
	{
		temp = arr[element_a];
		arr[element_a] = arr[element_b];
		arr[element_b] = temp;
	}
}

/**
 * merge - sort bitonic sequences recursively in both orders
 * @arr: the rray
 * @low: the first element
 * @n: the number of elements
 * @order: 1: ascending order, 0 descending order
 */
void merge(int arr[], int low, int n, int order)
{
	int mid, i;

	if (n > 1)
	{
		mid = n / 2;
		for (i = low; i < low + mid; i++)
			swap_e(arr, i, i + mid, order);
		merge(arr, low, mid, order);
		merge(arr, low + mid, mid, order);
	}
}
/**
 * bitonicsort - bitonic sort algorithm implementation
 * @arr: array
 * @low: first element
 * @n: number of elements
 * @order: 1: ascending order, 0 descending order
 * @size: array lenght
 */
void bitonicsort(int arr[], int low, int n, int order, int size)
{
	int mid;

	if (n > 1)
	{
		if (order >= 1)
		{
			printf("Merging [%i/%i] (UP):\n", n, size);
			print_array(&arr[low], n);
		}
		else
		{
			printf("Merging [%i/%i] (DOWN):\n", n, size);
			print_array(&arr[low], n);
		}
		mid = n / 2;
		bitonicsort(arr, low, mid, 1, size);
		bitonicsort(arr, low + mid, mid, 0, size);
		merge(arr, low, n, order);
		if (order <= 0)
		{
			printf("Result [%i/%i] (DOWN):\n", n, size);
			print_array(&arr[low], n);
		}
		if (order >= 1)
		{
			printf("Result [%i/%i] (UP):\n", n, size);
			print_array(&arr[low], n);
		}
	}
}
/**
 * bitonic_sort - prepare the terrain to bitonic sort algorithm
 * @array: array
 * @size: array lenght
 */
void bitonic_sort(int *array, size_t size)
{
	int order = 1;

	if (!array || size < 2)
		return;
	bitonicsort(array, 0, size, order, size);
}
