#include "sort.h"

/**
 * counting_sort - the counting sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: no return
 */

void counting_sort(int *array, size_t size)
{
	int max, i, j, count;

	if (!array || !size || size == 1)
		return;
	max = 0;
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	int *count_array = calloc(max + 1, sizeof(int));
	int *output_array = calloc(size, sizeof(int));

	if (!count_array || !output_array)
		return;
	for (i = 0, count = 0; i < max + 1; i++)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (array[j] == i)
			count++;
		}
		count_array[i] = count;
		count = 0;
	}
	for (i = 1; i < max + 1; i++)
		count_array[i] = count_array[i - 1] + count_array[i];
	print_array(count_array, max + 1);
	for (i = size - 1; i >= 0; i--)
		output_array[count_array[array[i]] - 1] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
