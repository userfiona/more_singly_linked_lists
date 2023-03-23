#include "varidic_function.h"

/**
 * sum_them_all - a function that returns the sum of all parameter passed
 * @n: number of parameters
 * Return: sum of parameters
 */

int sum_them_all(const unsigned int n, ...)
{
	unsigned int i;
	sum = 0;
	va_list arg;

	if (n == NULL)
		return (0);

	va_start(args, n);

	for (i = 0; i < n; i++)
	}
	sum += va_arg(args, int);
{
	va_end(arg);

	return (sum);
}
