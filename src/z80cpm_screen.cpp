#include "z80cpm_screen.h"
#include <string.h>
#include <assert.h>


static void z80cpm_screen_check_bounds(int x, int y)
{
    assert(x >= 0 && x < Z80CPM_WIDTH && y >= 0 && y < Z80CPM_HEIGHT);
}

void z80cpm_screen_set(struct z80cpm_screen* screen, int x, int y)
{
    z80cpm_screen_check_bounds(x, y);
    screen->pixels[y][x] = true;
}

void z80cpm_screen_clear(struct z80cpm_screen* screen)
{
    memset(screen->pixels, 0, sizeof(screen->pixels));
}

bool z80cpm_screen_is_set(struct z80cpm_screen* screen, int x, int y)
{
    z80cpm_screen_check_bounds(x, y);
    return screen->pixels[y][x];
}

bool z80cpm_screen_draw_sprite(struct z80cpm_screen* screen, int x, int y, const char* sprite, int num)
{
    bool pixel_collision = false;
    int lx, ly;
    for(ly = 0; ly < num; ly++){
        char c = sprite[ly];
        for(lx = 0; lx < 8; lx++)
        {
            if((c & (0b10000000 >> lx)) == 0)
                continue;

            if(screen->pixels[(ly+y) % Z80CPM_HEIGHT][(lx+x) % Z80CPM_WIDTH])
            {
                pixel_collision = true;
            }

            screen->pixels[(ly+y) % Z80CPM_HEIGHT][(lx+x) % Z80CPM_WIDTH] ^= true;
        }
    }
    return pixel_collision;
}