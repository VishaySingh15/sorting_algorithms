#include "sort.h"

/*
 *
 **/

void selection_sort(int *array, size_t size)
{
	size_t inner, outer;
	int pos, tmp;

	for (outer = 0; outer < size - 1; outer++)
	{
		pos = outer;
		for (inner = outer + 1; inner < size; inner++)
		{
			if (array[pos] > array[inner])
			{
				pos = inner;
			}
		}
		if (pos != (int)outer)
		{
			tmp = array[pos];
			array[pos] = array[outer];
			array[outer] = tmp;
			print_array(array, size);
		}
	}
}
