#ifndef Z80CPMMEMORY_H
#define Z80CPMMEMORY_H

#include "config.h"
struct z80cpm_memory
{
	unsigned char* memory; //[z80cpm_MEMORY_SIZE];
	unsigned char* rom; //[z80cpm_MEMORY_SIZE];

	char rom_disabled;
};

void z80cpm_memory_set(struct z80cpm_memory* memory, int index, unsigned char val);
unsigned char z80cpm_memory_get(struct z80cpm_memory* memory,int index);
unsigned short z80cpm_memory_get_short(struct z80cpm_memory* memory,int index);

//unsigned char RdZ80(struct z80cpm_memory* z80cpm_memory, unsigned short Address);
//void WrZ80(struct z80cpm_memory* z80cpm_memory, unsigned short Address, unsigned char V);
#endif