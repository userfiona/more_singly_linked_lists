#include "function_pointers.h"
#include <stdlib.h>
/**
 * array_iterator - excaute function given as parameter on each element of an array
 *@array: The array
 *@size: The size of array
 *@action: a pointer to function to be excauted
 */
void array_iterator(int *array, size_t size, void (*action)(int))
i{	
	if (array == NULL || action == NULL)
	return;
	while (size-- > 0)
	{
		action(*array);
		array++;

	}
}
