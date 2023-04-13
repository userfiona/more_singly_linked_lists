#include "main.h"

/**
 * read_textfile - reads a text file and prints a specified number of letters
 * @fn: name of the file to read
 * @num_letters: number of letters to read and print
 *
 * Return: the number of letters printed on success, or 0 on failure
 */
ssize_t read_textfile(const char *fn, size_t num_letters)
{
	int fn;
	ssize_t bytes_open, bytes_read, bytes_written;
	char *buffer;

	if (!fn)
		return (0);		

	
			buffer = malloc(sizeof(char) * (num_letters);
			if (!buffer)
				return (0);

				bytes_open = open(fn, O_RDONLY);

				bytes_read = read(bytes_open, buffer, num_letters);

				bytes_written = write(STDOUT_FILENO, buffer, bytes_read);

				if (bytes_open = -1 || bytes_read = -1 || bytes_written)
				{
					free(buffer);
					return (0);
				}

				free(buffer);
			    close(bytes_open);

				return (bytes_written);
}
