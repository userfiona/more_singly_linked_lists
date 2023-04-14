#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file
 * @filename: the name of the file to append to.
 * @text_content: the content to append to the file.
 *
 * Return: 1 if the file exists. -1 if the file does not exist
 * or if it fails to append the text.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int file_descriptor;
	int letters_written; 
	int result;

	if (!filename) 
		return (-1);

		file_descriptor = open(filename, O_WRONLY | O_APPEND); 

	if (file_descriptor == -1)
		return (-1);

		if (text_content) 
	{
		for (letters_written = 0; text_content[letters_written]; letters_written++)
			;

			result = write(file_descriptor, text_content, letters_written); 

			if (result == -1) 
			return (-1);
	}

	close(file_descriptor);
	return (1); 
}

