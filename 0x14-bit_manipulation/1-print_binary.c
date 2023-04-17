#include "main.h"
#include <stdio.h>

/**
 * print_binary - prints the binary representation of a decimal number
 * @n: decimal number to convert to binary and print
 */
void print_binary(unsigned long int n)
{
    unsigned long int l;
    int bit_count;

 
    if (n == 0)
    {
        printf("0");
        return;
    }

    
    for (l = n, bit_count = 0; (l >>= 1) > 0; bit_count++)
        ;

   
    for (; bit_count >= 0; bit_count--)
    {
        if ((n >> bit_count) & 1)
            printf("1");
        else
            printf("0");
    }
}
