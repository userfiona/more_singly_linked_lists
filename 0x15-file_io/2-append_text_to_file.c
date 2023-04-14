#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to append to
 * @text_content: text to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor, num_letters, re_value;

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_RDWR | O_APPEND);

	if (file_descriptor == -1)
		return (-1);

	if (text_content)
	{
		for (num_letters = 0; text_content[num_letters]; num_letters++)
			;

			re_value = write(file_descriptor, text_content, num_letters);

			if (re_value == -1)
			return (-1);
	}

	close(file_descriptor);

	return (1);
}
