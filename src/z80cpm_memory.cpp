#include "z80cpm_memory.h"
#include <assert.h>
#include <stdio.h>

static void z80cpm_is_memory_in_bounds(int index)
{
    assert(index >= 0 && index < Z80CPM_MEMORY_SIZE);
}

void z80cpm_memory_set(struct z80cpm_memory* z80cpm_memory, int index, unsigned char val)
{
    z80cpm_is_memory_in_bounds(index);
	z80cpm_memory->memory[index] = val;
}

unsigned char z80cpm_memory_get(struct z80cpm_memory* z80cpm_memory, int index)
{
    z80cpm_is_memory_in_bounds(index);
    return z80cpm_memory->memory[index];
}

unsigned short z80cpm_memory_get_short(struct z80cpm_memory* z80cpm_memory, int index)
{
    unsigned char byte1 = z80cpm_memory_get(z80cpm_memory, index);
    unsigned char byte2 = z80cpm_memory_get(z80cpm_memory, index + 1);

    return byte1 << 8 | byte2;
}

