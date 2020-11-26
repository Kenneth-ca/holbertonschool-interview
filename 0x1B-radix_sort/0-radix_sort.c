#include "sort.h"

/**
 * radix_count - auxiliar function to count for radix
 * @array: the array to sort
 * @size: size of the array
 * @exponent: the number to be raised by a power
 * Return: nothing
 */
void radix_count(int *array, int size, int exponent)
{
	int *output = NULL;
	int i = 0;
	int aux[10] = {0};

	output = malloc(size * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		aux[(array[i] / exponent) % 10]++;

	for (i = 1; i < 10; i++)
		aux[i] += aux[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		output[aux[(array[i] / exponent) % 10] - 1] = array[i];
		aux[(array[i] / exponent) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}
/**
 * radix_sort - sorts an array using radix sort
 * @array: the array to sort
 * @size: size of the array
 * Return: nothing
 */
void radix_sort(int *array, size_t size)
{
	int max = 0, exponent = 0;
	size_t i = 0;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	for (exponent = 1; max / exponent > 0; exponent *= 10)
	{
		radix_count(array, size, exponent);
		print_array(array, size);
	}
}
