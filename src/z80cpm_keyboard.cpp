#include "z80cpm_keyboard.h"
#include <assert.h>

static void z80cpm_keyboard_ensure_in_bounds(int key){
    assert(key >= 0 && key < Z80CPM_TOTAL_KEYS);
}

void z80cpm_keyboard_set_map(struct z80cpm_keyboard* keyboard, const unsigned int* map)
{
    keyboard->keyboard_map = map;
    int i;
    for(i = 0; i < Z80CPM_TOTAL_KEYS; i++)
        keyboard->keyboard[i] = false;
}

int z80cpm_keyboard_map(struct z80cpm_keyboard* keyboard, int key)
{
    
    int i;
    for(i = 0; i < Z80CPM_TOTAL_KEYS; i++)
    {
        if(keyboard->keyboard_map[i] == key)
        {
            return i;
        }
    }

    return -1;
}

void z80cpm_keyboard_down(struct z80cpm_keyboard* keyboard, int key)
{
    keyboard->keyboard[key] = true;
}

void z80cpm_keyboard_up(struct z80cpm_keyboard* keyboard, int key)
{
    keyboard->keyboard[key] = false; 
}

bool z80cpm_keyboard_is_down(struct z80cpm_keyboard* keyboard, int key)
{
    return keyboard->keyboard[key];
}