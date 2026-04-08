#include "sort.h"

/**
 * lomuto_partition - partitions array using Lomuto scheme
 * @array: the array
 * @lo: left index
 * @hi: right index
 * @size: full size of array
 * Return: pivot index
 */
static int lomuto_partition(int *array, int lo, int hi, size_t size)
{
	int pivot;
	int tmp;
	int i;
	int j;

	pivot = array[hi];
	i = lo - 1;
	for (j = lo; j < hi; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] != array[hi])
	{
		tmp = array[i + 1];
		array[i + 1] = array[hi];
		array[hi] = tmp;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - recursive quicksort helper
 * @array: the array
 * @lo: left index
 * @hi: right index
 * @size: full size of array
 */
static void quicksort(int *array, int lo, int hi, size_t size)
{
	int p;

	if (lo < hi)
	{
		p = lomuto_partition(array, lo, hi, size);
		quicksort(array, lo, p - 1, size);
		quicksort(array, p + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array using quick sort
 * @array: the array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, (int)size - 1, size);
}
