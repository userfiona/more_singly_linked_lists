#include "main.h"

/**
 * create_file - creates a new file and writes content to it
 * @filename: the name of the file to be created
 * @text_content: the content to be written to the file
 *
 * Return: 1 on Success or -1 upon failure
 */
int create_file(const char *filename, char *text_content)
{
	int file_descriptor, i, write_status;

	/* If filename is NULL, return error */
	if (filename == NULL)
	{
		return (-1);
	}

	/* Open file with given filename and permissions */
	file_descriptor = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);

	/* If the file could not be created, return error */
	if (file_descriptor == -1)
	{
		return (-1);
	}
	/* If text_content is NULL, set it to an empty string */
	if (text_content == NULL)
	{
		text_content = "";
	}
	/* Find the length of the string in text_content */
	for (i = 0; text_content[i] != '\0'; i++)
		;

		/* Write text_content to the file */
		write_status = write(file_descriptor, text_content, i);

		/* If there was an error writing to the file, return error */
		if (write_status == -1)
		{
			return (-1);

			}

			/* Close the file and return success */
			close(file_descriptor);
			return (1);
}
