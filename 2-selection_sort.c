#include "sort.h"

/**
 * selection_sort()- the selection sort algorithm!
 * @array: the array to sort
 * @size: the size of the array!
 *
 * Return: No return
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min;

	for (i = 0; i < size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
			if (min != i)
			{
				swap(&array[min], &array[i]);
				print_array(array, size);
			}
		}
	}

}

/**
 * swap()- utility func to swap two positions
 * @a: postion one
 * @b: position two
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
