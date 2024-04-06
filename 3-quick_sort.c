#include "sort.h"

int partition(int *array, int low, int high, size_t size);
void swap(int *a, int *b);
void quicksort_s(int *array, int low, int high, size_t size);

/**
 * quick_sort()- a very speedy sort!
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: no return
 */

void quick_sort(int *array, size_t size)
{
	quicksort_s(array, 0, size - 1, size);
}

/**
 * swap()- swaps two array elements
 * @a: el one
 * @b: el two
 *
 * Return: no return
 */

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}


/**
 * partition()- creates a partition
 * @array: the array
 * @low: the low end
 * @high: the high end
 * @size: size of the array
 *
 * Return: the partition
 */

int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (array[i] != array[j])
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
	
}

/**
 * quicksort_s()- the acutal algorithm
 * @array: the array to be sorted
 * @low: the low
 * @high: the high
 * @size: the size of the array
 *
 * Return: no return
 */

void quicksort_s(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi;

		pi = partition(array, low, high, size);

		quicksort_s(array, low, pi - 1, size);
		quicksort_s(array, pi + 1, high, size);
	}
}
