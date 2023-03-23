#include "variadic_functions.h"

/**
*print_numbers - print all numbers passed
*@separaror: character that separate the number
*@n: number of integers
*/
void print_numbers(const char *separator, const unsigned int, ...)
{
	unsigned int i;
	va_list; args;

	va_start(arg, n);
	for (i = 0; 1 < n; 1++)

	{
	if (i > 0 && != NULL)
		printf("%s", separator);
	printf("%d", va_arg(args, int));
}
	va_end(args);
	printf("\n");
}
