#ifndef Z80CPMSCREEN_H
#define Z80CPMSCREEN_H

#include <stdbool.h>
#include "config.h"
struct z80cpm_screen
{
    bool pixels[Z80CPM_HEIGHT][Z80CPM_WIDTH];
};

void z80cpm_screen_set(struct z80cpm_screen* screen, int x, int y);
void z80cpm_screen_clear(struct z80cpm_screen* screen);
bool z80cpm_screen_is_set(struct z80cpm_screen* screen, int x, int y);
bool z80cpm_screen_draw_sprite(struct z80cpm_screen* screen, int x, int y, const char* sprite, int num);
#endif