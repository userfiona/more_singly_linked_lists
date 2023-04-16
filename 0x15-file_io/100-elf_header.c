#include <elf.h> // ELF header definitions
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

int main(int argc, char *argv[])
{
    int fd;
    unsigned char e_ident[EI_NIDENT];
    Elf64_Ehdr e_hdr;

    if (argc < 2) {
        dprintf(STDERR_FILENO, "Usage: %s elf_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (read(fd, e_ident, EI_NIDENT) != EI_NIDENT) {
        dprintf(STDERR_FILENO, "read error\n");
        exit(EXIT_FAILURE);
    }

    check_elf(e_ident);
    lseek(fd, 0, SEEK_SET);
    if (read(fd, &e_hdr, sizeof(e_hdr)) != sizeof(e_hdr)) {
        dprintf(STDERR_FILENO, "read error\n");
        exit(EXIT_FAILURE);
    }

    print_magic(e_ident);
    print_class(e_ident);
    print_data(e_ident);
    print_version(e_ident);
    print_abi(e_ident);
    print_osabi(e_ident);
    print_type(e_hdr.e_type, e_ident);
    print_entry(e_hdr.e_entry, e_ident);

    close_elf(fd);
    return 0;
}

// Checks if the file is an ELF file. If not, exits with code 98.
void check_elf(unsigned char *e_ident)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (e_ident[i] != 127 &&
            e_ident[i] != 'E' &&
            e_ident[i] != 'L' &&
            e_ident[i] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
        }
    }
}

// Prints the magic numbers of an ELF header.
void print_magic(unsigned char *e_ident)
{
    int i;

    printf("  Magic:   ");
    for (i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", e_ident[i]);
    }
    printf("\n");
}

// Prints the class of an ELF header.
void print_class(unsigned char *e_ident)
{
    printf("  Class:                             ");
    switch (e_ident[EI_CLASS]) {
    case ELFCLASSNONE:
        printf("none\n");
        break;
    case ELFCLASS32:
        printf("ELF32\n");
        break;
    case ELFCLASS64:
        printf("EL");

