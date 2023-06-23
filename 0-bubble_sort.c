#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array to sort
 * @size: size of array
 * Return: no return
 */

void bubble_sort(int *array, size_t size)
{
	size_t inner, outer;
	int temp, flag;

	for (outer = size - 1; outer > 0; outer--)
	{
		flag = 0;
		for (inner = 0; inner < outer; inner++)
		{
			if (array[inner] > array[inner + 1])
			{
				temp = array[inner];
				array[inner] = array[inner + 1];
				array[inner + 1] = temp;
				flag = 1;
				print_array(array, size);
			}
		}
		if (!flag)
		{
			break;
		}
	}
}
