#include <stdio.h>
#include <stdlib.h>
#include "myelf.h"

int i;
void printmagic(struct elf *obj);
struct elf *obj; 
extern int elfhdr_print(FILE *fp);
extern int section_hdr_print ( FILE *fp );

int elfhdr_print(FILE *fp)
{

	obj = (struct elf *) malloc (sizeof(struct elf));

	fread(obj, sizeof(struct elf), 1, fp);

	if (obj->e_iden[0] == 0x7f) {

		printf ("ELF Header:\n");

		printmagic(obj);

		printf (" Version     				0x%u\n", obj->e_version);
		printf (" Entry point addres			0x%x\n", obj->e_entry);
		printf (" Start of program headers		%u (bytes into file)\n", obj->e_phoff);
		printf (" Start of section headers		%u (bytes into file)\n", obj->e_shoff);
		printf (" Flags					0x%u\n", obj->e_flags);
		printf (" Size of elf header			%u (bytes)\n", obj->e_ehsize);
		printf (" Size of program header			%u (bytes)\n", obj->e_phentsize);
		printf (" Number of program header		%u\n", obj->e_phnum);
		printf (" Size of section header			%u (bytes)\n", obj->e_shentsize);
		printf (" Number of section header		%u\n", obj->e_shnum);
		printf (" Section header string table index	%u\n\n", obj->e_shstrndx);

	} else {
		printf ("No such file\n");
	}
	fclose (fp);
	return 0;
}
void printmagic(struct elf *obj)
{

	printf (" Magic:	");
	for (i = 0; i < EI_NIDENT; i++) {
		printf ("%02x ", obj->e_iden[i]);
	}
	printf ("\n Class					");
		
	if (obj->e_iden[EI_CLAS] == 0) {
		printf ("Invalid class\n"); 
	} else if (obj->e_iden[EI_CLAS] == 1) {
		printf ("ELF32\n"); 
	} else if (obj->e_iden[EI_CLAS] == 2) {
		printf ("ELF64\n"); 
	}

	printf (" Data					");

	if (obj->e_iden[5] == 0) {
		printf ("Invalid data\n"); 
	} else if (obj->e_iden[5] == 1) {
		printf ("2's complement, little endian\n"); 
	} else if (obj->e_iden[5] == 2) {
		printf ("2's complement, big endian\n"); 
	}

	if (obj->e_version == 0) {
		printf (" Invalid class\n"); 
	} else if (obj->e_version == 1) {
		printf (" Version     				%u (current)\n", obj->e_version);
	}

	printf (" OS/ABI Version				UNIX - System v\n ABI Version				0\n");

	printf (" Type					");
	
	switch (obj->e_type) {

	case 0 : printf ("No file type\n"); 
			 break;
	case 1 : printf ("REL (relocatable file)\n"); 
			 break;
	case 2 : printf ("EXEC (Executable file)\n"); 
			 break;
	case 3 : printf ("SHARE (Shared obj file)\n"); 
			 break;
	}

	printf (" Machine				");
	
	switch (obj->e_machine) {
	
	case 0 : printf ("No machine\n"); 
			 break;
	case 1 : printf ("AT&T WE 32100\n"); 
			 break;
	case 2 : printf ("SPARC\n"); 
			 break;
	case 3 : printf ("Intel_386	Intel Architecture\n"); 
			 break;
	case 4 : printf ("Motorola 68000\n"); 
			 break;
	case 7 : printf ("Intel_860	Intel Architecture\n"); 
			 break;
	case 8 : printf ("MIPS RS3000 BIG-Endian\n"); 
			 break;
	}
}

int section_hdr_print ( FILE *fp )
{
	char *buf = NULL;
	struct secthed obj1[obj->e_shnum];

	fp = fopen ("elf", "r");
	obj = (struct elf *) malloc (sizeof(struct elf));

	fread (obj, sizeof(struct elf), 1, fp);

	fseek (fp, obj -> e_shoff, SEEK_SET);
	fread (obj1, sizeof(obj1), 1, fp);

	buf = (char *) malloc (sizeof(char) * obj1[obj -> e_shstrndx].size);

	fseek (fp, obj1[obj -> e_shstrndx].off, SEEK_SET); 
	fread (buf, obj1[obj -> e_shstrndx].size, 1, fp); 

	printf(" [Nr] ");
	printf ("Name 		  ");
	printf ("Type 		");
	printf (" Addr 	  ");
	printf ("Off	 ");
	printf ("Size	");
	printf ("ES ");
	printf ("Flg ");
	printf ("Lk ");
	printf ("Inf ");
	printf ("Al\n");

	for (i = 0; i < obj -> e_shnum ; i++) { 
		printf (" [%2d] ", i);
		printf ("%-19s ", (buf + obj1[i].name));

		switch (obj1[i].type) {

		case 0 : printf ("NULL		");
				 break;
		case 1 : printf ("PROGBITS	");
				 break;
		case 2 : printf ("SYMTAB	");
				 break;
		case 3 : printf ("STRTAB	");
				 break;
		case 4 : printf ("RELA		");
				 break;
		case 5 : printf ("GNU_HASH	");
				 break;
		case 6 : printf ("DYNAMIC	");
				 break;
		case 7 : printf ("NOTE		");
				 break;
		case 8 : printf ("NOBITS	");
				 break;
		case 9 : printf ("REL		");
				 break;
		case 10 : printf ("SHLIB	");
				 break;
		case 11 : printf ("DYNSYM	");
				 break;
		default : printf ("		");
				 break;
		}

		printf (" %08x ", obj1[i].addr);
		printf ("%06x ", obj1[i].off);
		printf ("%06x ", obj1[i].size);
		printf ("%02d ", obj1[i].es);

		switch (obj1[i].flg) {

		case 0 : printf ("    ");
				 break;
		case 1 : printf ("  W ");
				 break;
		case 2 : printf ("  A ");
				 break;
		case 3 : printf (" WA ");
				 break;
		case 6 : printf (" AX ");
				 break;
		case 48 : printf (" MS ");
				 break;
		}

		printf ("%2d", obj1[i].lk);
		printf ("%4d ", obj1[i].inf);
		printf ("%2d\n", obj1[i].al);
	}

	fclose(fp);
	return 0;
}
