#include "sort.h"

/**
 * merge_sort - the merge sort algorithm
 * @array: the array to sort
 * @size: the size of the array
 *
 * Return: no return
 */

void merge_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	merge_sort_recursive(array, 0, size - 1);
}


/**
 * merge - the meat of the merge sort function
 * @array: the array to sort
 * @left: the left
 * @mid: the mid
 * @right: the right
 *
 * Return: no return
 */

void merge(int *array, int left, int mid, int right)
{
	int i, j, k, left_size, right_size, left_array[1024], right_array[1024];

	left_size = mid - left + 1;
	right_size = right - mid;

	for(i = 0; i < left_size; i++)
		left_array[i] = array[left + i];
	for(j = 0; j < right_size; j++)
		right_array[j] = array[mid + 1 + j];
	printf("Merging...\n");
	printf("[left] ");
	print_array(left_array, left_size);
	printf("[right] ");
	print_array(right_array, right_size);
	i = 0, j = 0, k = left;

	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	while (i < left_size)
		array[k++] = left_array[i++];
	while (j < right_size)
		array[k++] = right_array[j++];
	printf("[Done] ");
	print_array(&array[left], right - left + 1);
}


/**
 * merge_sort_recursive - the recursive call in merge sort
 * @array: the array we're sorting
 * @left: the left
 * @right: the right
 *
 * Return: no return
 */

void merge_sort_recursive(int *array, int left, int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		merge_sort_recursive(array, left, mid);
		merge_sort_recursive(array, mid + 1, right);
		merge(array, left, mid, right);
	}
}

