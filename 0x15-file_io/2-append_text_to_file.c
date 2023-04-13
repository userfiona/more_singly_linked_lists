#include "main.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: name of the file to append to
 * @text_content: text to append
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	// Declare file descriptor, number of letters, and return value
	int file_descriptor, num_letters, return_value;

	// If filename is NULL, return -1
	if (!filename)
		return (-1);

	// Open file in write-only and append mode
	file_descriptor = open(filename, O_WRONLY | O_APPEND);

	// If open fails, return -1
	if (file_descriptor == -1)
		return (-1);

	// If text_content is not NULL, count the number of letters
	if (text_content)
	{
		for (num_letters = 0; text_content[num_letters]; num_letters++)
			;
		// Write text_content to file
		return_value = write(file_descriptor, text_content, num_letters);
		// If write fails, return -1
		if (return_value == -1)
			return (-1);
	}

	// Close file
	close(file_descriptor);

	// Return 1 to indicate success
	return (1);
}
