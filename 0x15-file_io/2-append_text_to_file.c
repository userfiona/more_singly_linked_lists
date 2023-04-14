#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file to append text to.
 * @text_content: the text content to be appended to the file.
 *
 * Return: 1 if successful, -1 if the file does not exist or if the operation fails.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor; 
	int num_of_chars; 
	int write_return; 

	if (!filename)
		return (-1);

	file_descriptor = open(filename, O_WRONLY | O_APPEND); 

	if (file_descriptor == -1) 
		return (-1);

	if (text_content) 
	{
		for (num_of_chars = 0; text_content[num_of_chars]; num_of_chars++) 
			;

		write_return = write(file_descriptor, text_content, num_of_chars);

		if (write_return == -1) 
			return (-1);
	}

	close(file_descriptor);

	return (1); 
}

