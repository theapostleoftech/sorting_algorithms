#include "sort.h"
/**
 * _calloc - this is a calloc function
 * @element: the number of elements
 * @size: the size of the elements in bits
 * Return: pointer to memory
 */
void *_calloc(unsigned int element, unsigned int size)
{
	unsigned int i = 0;
	char *ptr;

	if (element == 0 || size == 0)
		return (NULL);
	ptr = malloc(element * size);
	if (ptr == NULL)
		return (NULL);
	for (i = 0; i < (element * size); i++)
		ptr[i] = 0;
	return (ptr);
}

