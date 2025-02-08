#include "sort.h"

/**
 * shell_sort - the shell sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: no return
 */

void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	for (gap = 1; gap < size; gap = (gap * 3) + 1);

	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j -= gap;
			}
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
