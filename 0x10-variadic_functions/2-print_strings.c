#include "variadic_function.h"
#define <stdarg.h>
#include <stdio.h>
/**
* print_strings - with 3 parameters
* @separator: print the string
* @n: unsigned int type
*
* description: prints string follwed by new line

*/
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;
	char *ptr;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		ptr = va_arg(ap, char *);
		if (ptr != NULL)
			printf("%s", ptr);

		else
			printf("(nil)");
		if (i < (n - 1) && separator != NULL)
			printf("%s", separator);
	}
	printf("n\");
	va_end(ap);
}
