#include "sort.h"

/*
 * quick_sort - sorts array using lumuto sequence
 * @array: array to sort
 * @size: array size
 * Return: no return
 **/

void quick_sort(int *array, size_t size)
{
	my_sort(array, size, array, size);
}

/*
 * my_sort - allows for my recursion
 * @array: original array
 * @arr_size: orginal array size
 * @arr: modified array
 * @size: modified array size
 * Return: no return
 **/

void my_sort(int *array, size_t arr_size, int *arr, size_t size)
{
	size_t cu, cd = 0;
        int tmp;

        if (size < 2)
                return;

        for (cu = 0; cu < size; cu++)
        {
		if (arr[cu] <= arr[size - 1])
                {
			if (cu > cd)
			{
				tmp = arr[cu];
				arr[cu] = arr[cd];
				arr[cd] = tmp;
				print_array(array, arr_size);
			}
                        cd++;
			if (cd == size)
				cd--;
                }
        }
        my_sort(array, arr_size, arr, cd);
        my_sort(array, arr_size, &array[cd], size - cd);
}
