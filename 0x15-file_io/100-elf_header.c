#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

void display_elf_header_info(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error: Failed to open file");
        exit(EXIT_FAILURE);
    }

   
    Elf64_Ehdr elf_header;
    ssize_t num_read = read(fd, &elf_header, sizeof(Elf64_Ehdr));
    if (num_read < sizeof(Elf64_Ehdr)) {
        perror("Error: Failed to read ELF header");
        exit(EXIT_FAILURE);
    }

   
    if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
        elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
        elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
        elf_header.e_ident[EI_MAG3] != ELFMAG3) {
        perror("Error: Not an ELF file");
        exit(EXIT_FAILURE);
    }

   
    printf("Magic:  ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");

    printf("Class:  ");
    switch (elf_header.e_ident[EI_CLASS]) {
        case ELFCLASSNONE:
            printf("none\n");
            break;
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("unknown\n");
            break;
    }

    printf("Data:  ");
    switch (elf_header.e_ident[EI_DATA]) {
        case ELFDATANONE:
            printf("none\n");
            break;
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("unknown\n");
            break;
    }

    printf("Version:  %d\n", elf_header.e_ident[EI_VERSION]);

    printf("OS/ABI:  ");
    switch (elf_header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;

