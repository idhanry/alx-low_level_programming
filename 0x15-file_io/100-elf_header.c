#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <elf.h>
#include <string.h>
#include <errno.h>

void print_error(const char message)
{
fprintf(stderr, "%s\n", message);
exit(98);
}

int main(int argc, char argv[])
{
if (argc != 2)
{
	print_error("Usage: elf_header elf_filename");
}

const char filename = argv[1]
int fd = open(filename, O_RDONLY);
if (fd == -1)
{
	print_error(strerror(errno));
}

	Elf64_Ehdr header;
if (read(fd, &header, sizeof(Elf64_Ehdr))
	!= sizeof(Elf64_Ehdr))
{
	print_error("Error reading ELF header");
}

/* Check if it's an ELF file */
if (memcmp(header.e_ident, ELFMAG,
	SELFMAG) != 0)
{
	print_error("Not an ELF file");
}

printf("Magic:");
for (int i = 0; i < EI_NIDENT; i++)
{
	printf(" %02x", header.e_ident[i]);
}
printf("\n");

printf("Class: %d-bit\n", header.e_ident
		[EI_CLASS]
== ELFCLASS32 ? 32 : 64);

printf("Data: %s\n", header.e_ident
		[EI_DATA] == ELFDATA2LSB ?
	"2's complement, little-endian" :
	"Unknown");

printf("Version: %d\n", header.e_ident
		[EI_VERSION]);

printf("OS/ABI: %s\n", header.e_ident
		[EI_OSABI] == ELFOSABI_SYSV ?
	"UNIX System V ABI" : "Unknown");

printf("ABI Version: %d\n",
		header.e_ident
		[EI_ABIVERSION]);

printf("Type: ");
	switch (header.e_type)
{
	case ET_NONE:
		printf("NONE (No file type)\n");
		break;
	case ET_REL:
		 = printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("Unknown\n");
		break;
}

printf("Entry point address: 0x%lx\n",
		(unsigned long)
header.e_entry);

close(fd);

return (0);
}
