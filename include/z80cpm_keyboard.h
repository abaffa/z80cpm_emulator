#ifndef Z80CPMKEYBOARD_H
#define Z80CPMKEYBOARD_H

#include <stdbool.h>
#include "config.h"
struct z80cpm_keyboard
{
    bool keyboard[Z80CPM_TOTAL_KEYS];
    const unsigned int* keyboard_map;
};

void z80cpm_keyboard_set_map(struct z80cpm_keyboard* keyboard, const unsigned int* map);
int z80cpm_keyboard_map(struct z80cpm_keyboard* keyboard, int key);
void z80cpm_keyboard_down(struct z80cpm_keyboard* keyboard, int key);
void z80cpm_keyboard_up(struct z80cpm_keyboard* keyboard, int key);
bool z80cpm_keyboard_is_down(struct z80cpm_keyboard* keyboard, int key);

#endif