#include "search_algos.h"

/**
 * binary_search - recursion for the searching
 * @array: array in which to search
 * @first: first index
 * @last: last index
 * @value: value to be searched
 * Return: index of number or -1 if not found
 */
int binary_search(int *array, int first, int last, int value)
{
	int mid, i;

	printf("Searching in array: ");
	for (i = first; i < last; i++)
		printf("%i, ", array[i]);
	printf("%i\n", array[i]);

	mid = ((last - first) / 2) + first;

	if (array[mid] == value && array[mid - 1] != value)
		return (mid);

	if (first == last)
		return (-1);

	if (array[mid] >= value)
		return (binary_search(array, first, mid, value));

	if (array[mid] < value)
		return (binary_search(array, mid + 1, last, value));

	return (-1);
}


/**
 * advanced_binary - searches for a value in a sorted array of integers
 * @array: array in which to search
 * @size: size of the array
 * @value: value to be searched
 * Return: index of number or -1 if not found
 */
int advanced_binary(int *array, size_t size, int value)
{
	size_t left = 0;
	size_t right = size - 1;

	if (!array)
		return (-1);

	return (binary_search(array, left, right, value));
}
