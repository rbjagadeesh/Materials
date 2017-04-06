#define EI_NIDENT 16
#define EI_CLAS 4

typedef unsigned int Elf32_Add;
typedef unsigned short Elf32_Hal;
typedef unsigned int Elf32_Off;

struct elf {

	unsigned char e_iden[EI_NIDENT];
	Elf32_Hal e_type;
	Elf32_Hal e_machine;
	Elf32_Off e_version;
	Elf32_Add e_entry;
	Elf32_Off e_phoff;
	Elf32_Off e_shoff;
	Elf32_Off e_flags;
	Elf32_Hal e_ehsize;
	Elf32_Hal e_phentsize;
	Elf32_Hal e_phnum;
	Elf32_Hal e_shentsize;
	Elf32_Hal e_shnum;
	Elf32_Hal e_shstrndx;
};

struct secthed 
{
	unsigned int name;	
	unsigned int type;	
	unsigned int flg;	
	unsigned int addr;	
	unsigned int off;	
	unsigned int size;	
	unsigned int lk;	
	unsigned int inf;	
	unsigned int al;	
	unsigned int es;	

};
