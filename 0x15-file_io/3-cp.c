#include "main.h" // include the header file
#include <stdio.h> // include the standard input/output library
/**
 * error_file - checks if files can be opened.
 * @file_from: file_from.
 * @file_to: file_to.
 * @argv: arguments vector.
 * Return: no return.
 */
void error_file(int file_from, int file_to, char *argv[])
{
	// check if file_from cannot be opened
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]); // print error message to stderr
		exit(98); // exit the program with error code 98
	}
	// check if file_to cannot be opened
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]); // print error message to stderr
		exit(99); // exit the program with error code 99
	}
}

/**
 * main - check the code for ALX students.
 * @argc: number of arguments.
 * @argv: arguments vector.
 * Return: Always 0.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to, err_close; // declare variables
	ssize_t nchars, nwr; // declare variables of type ssize_t and size of nchars and nwr
	char buf[1024]; // declare buffer array of 1024 bytes

	// check if the number of arguments is correct
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s\n", "Usage: cp file_from file_to"); // print error message to stderr
		exit(97); // exit the program with error code 97
	}

	// open the file_from for reading only
	file_from = open(argv[1], O_RDONLY);

	// create the file_to for writing only, and truncate it to zero length or create it if it does not exist
	// also set the file permissions to rw-rw-r--
	file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, 0664);

	// call error_file function to check if files were opened correctly
	error_file(file_from, file_to, argv);

	nchars = 1024; // set nchars to 1024
	while (nchars == 1024)
	{
		// read from file_from into the buffer array of 1024 bytes
		nchars = read(file_from, buf, 1024);
		if (nchars == -1) // check if there was an error reading from file_from
			error_file(-1, 0, argv); // call error_file function with appropriate parameters
		// write from the buffer array into file_to, writing nchars bytes
		nwr = write(file_to, buf, nchars);
		if (nwr == -1) // check if there was an error writing to file_to
			error_file(0, -1, argv); // call error_file function with appropriate parameters
	}

	// close the file_from and check if there was an error
	err_close = close(file_from);
	if (

