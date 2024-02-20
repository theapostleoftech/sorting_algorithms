#include "sort.h"
/**
 * merge - function to make a merge
 * @array: one from start to mid
 * @temp: temporary array
 * @start: the first element of the array
 * @mid: the middle element in the array
 * @end: last element position
 **/
void merge(int *array, int *temp, int start, int mid, int end)
{
	int sl = mid - start + 1, sr = end - mid;
	int *al, *ar;
	
	int left, right, i = 0;

	al = &temp[0];
	ar = &temp[sr];
	for (left = 0; left < sl; left++)
		al[left] = array[start + left];
	for (right = 0; right < sr; right++)
		ar[right] = array[mid + 1 + right];
	left = 0, right = 0, i = start;
	
	while (left < sl && right < sr)
	{
		if (al[left] <= ar[right])
			array[i] = al[left], left++;
		else
			array[i] = ar[right], right++;
		i++;
	}
	
	while (left < sl)
		array[i] = al[left], left++, i++;
	
	while (right < sr)
		array[i] = ar[right], right++, i++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(al, left);
	printf("[right]: ");
	print_array(ar, right);
	printf("[Done]: ");
	print_array(&array[start], left + right);
}

/**
 * mergesort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @array: array of integers
 * @temp: temp array
 * @start: fisrt element position
 * @end: last element position
 * Return: void
 */
void mergesort(int *array, int *temp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, temp, start, mid);
		mergesort(array, temp, mid + 1, end);
		merge(array, temp, start, mid, end);
	}
}

/**
 * merge_sort - function that sorts an array of integers
 * in ascending order using the Merge sort algorithm
 * @size: size of the list
 * @array: array of integers
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;
	temp = _calloc(size, sizeof(int));
	mergesort(array, temp, 0, size - 1);
	free(temp);
}
