#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define EMULATOR_WINDOW_TITLE "Z80CPM Emulator"

#define DEBUG_OPCODE 0
#define SERVER_WEB 0
#define SERVER_TELNET 1

#define Z80CPM_MEMORY_SIZE 0xFFFF //0x100
#define Z80_PROGRAM_LOAD_ADDRESS 0X000
#define Z80CPM_WIDTH 256 //32 x 8
#define Z80CPM_HEIGHT 200 // 25 x 8
#define Z80CPM_BORDER 40
#define Z80CPM_WINDOW_MULTIPLIER 2


#define Z80_TOTAL_DATA_REGISTERS 16
#define Z80_TOTAL_STACK_DEPTH 16
#define Z80CPM_TOTAL_KEYS 41
#define Z80_CHARACTER_SET_LOAD_ADDRESS 0x00
#define Z80_DEFAULT_SPRITE_HEIGHT 5

#define Z80CPM_IDE_MEMORY_SIZE 6.4e+7

#endif

