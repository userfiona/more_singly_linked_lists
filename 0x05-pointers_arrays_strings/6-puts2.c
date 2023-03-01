#include "main.h"

/**
<<<<<<< HEAD
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char *str;

    str = "0123456789";
    puts2(str);
    return (0);
=======
 * puts2 - Entry point
 * Description: Print every other character
 * @str: Character
 * Return: string
 */

void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (i % 2 == 0)
		{
			_putchar(str[i]);
		}
		i++;
	}
	_putchar('\n');
>>>>>>> aaad854d440df775e797e280daffff2d3c3c960e
}
