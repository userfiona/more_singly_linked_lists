#include "main.h"

/**
 * read_textfile - reads a text file and prints a specified number of letters
 * @filename: name of the file to read
 * @num_letters: number of letters to read and print
 *
 * Return: the number of letters printed on success, or 0 on failure
 */
ssize_t read_textfile(const char *filename, size_t num_letters)
{
	int file_descriptor;
	ssize_t bytes_read, bytes_written;
	char *buffer;

	if (!filename)
		return (0);

		file_descriptor = open(filename, O_RDONLY);

		if (file_descriptor == -1)
			return (0);

			buffer = malloc(sizeof(char) * (num_letters);
			if (!buffer)
				return (0);

				bytes_read = read(file_descriptor, buffer, num_letters);

				bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

				close(file_descriptor);

				free(buffer);

				return (bytes_written);
}
