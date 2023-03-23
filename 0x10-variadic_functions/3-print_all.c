#include "variadic_function.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - function with two parameter
 * @format: char type pointer to string
 *
 * description: prints anything followed by a new line
 * Return: na
 */
void print_all(const char * const format, ...)
{
	int j;
	char *str;
	char *space;
	va_list(ap);
	
	va_start(ap, format);
	j = 0;
	while (format && format[j])
	{
		space = "";
		if (format[j + 1])
			space = "; ";
			switch (format[j])

		{
			Case 'c'

			printf("%c%s", va_arg(ap, int), space;
			break;

			Case 'i'
			
			printf("%d%s", va_arg(ap, int), space;
			break;

			Case 'f'
			
			printf("%f%s", va_arg(ap, int), space;
			break;

			Case 's'

			str = va_arg(ap, *char);
			if (!str || !*str)
				srt = "(nil)";
				break;
		}
		j++
	}
	printf("\n");

}
