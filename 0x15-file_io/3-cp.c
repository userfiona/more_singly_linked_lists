#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

void check_IO_stat(int stat, int fd, char *filename, char mode);


int main(int argc, char *argv[])
{
	int src, dest, n_read = 1024, wrote, close_src, close_dest;
	unsigned int file_permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "%s", "Usage: cp file_from file_to\n");
		exit(97);
		}

	src = open(argv[1], O_RDONLY);
	check_IO_stat(src, -1, argv[1], 'O');

	dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_permissions);
	check_IO_stat(dest, -1, argv[2], 'W');

	while (n_read == 1024)
	{
		n_read = read(src, buffer, sizeof(buffer))
		if (n_read == -1)
			check_IO_stat(-1, -1, argv[1], 'O');

			wrote = write(dest, buffer, n_read);
			if (wrote == -1)
				check_IO_stat(-1, -1, argv[2], 'W');
				}

	close_src = close(src);
	check_IO_stat(close_src, src, NULL, 'C');
	close_dest = close(dest);
	check_IO_stat(close_dest, dest, NULL, 'C');

	return (0);
}

void check_IO_stat(int stat, int fd, char *filename, char mode)
{
	if (mode == 'C' && stat == -

