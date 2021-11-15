//
// hw_ide.cpp
//
////// BEGIN LICENSE NOTICE//////
//
//Z80 CPM Emulator - based on CP/M on breadboard by Grant Searle (http://searle.x10host.com/cpm/index.html)
//
//Copyright(C) 2021 Augusto Baffa, (cpm.baffasoft.com.br)
//
//This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.
//
//This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110 - 1301, USA.
//
////// END LICENSE NOTICE//////
//
#include "hw_ide.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>

void hw_ide_init(struct hw_ide* hw_ide) {

	int address = 0;
	hw_ide->lba_size = 512;
	hw_ide->save = 0;

	hw_ide->memory = (unsigned char*)malloc(Z80CPM_IDE_MEMORY_SIZE * sizeof(unsigned char));

	for (address = 0; address < Z80CPM_IDE_MEMORY_SIZE; address++) {
		hw_ide->memory[address] = 0x00;
	}

	for (address = 0; address < 8; address++) {
		hw_ide->data[address] = 0x00;
	}

	hw_ide_reset(hw_ide);
}

void hw_ide_reset(struct hw_ide* hw_ide) {
	hw_ide->gambi_ide_total = 0;
	hw_ide->gambi_ide_read = 0;
}



int chs(int lba, int C = 1024, int H = 255, int S = 63) {
	/*
	'lba' linearly addresses sector, indexing from zero.
	'C', 'H', 'S' specify geometry - fixed for a given disk :
	1 <= C <= 1024 (10 bits)
	1 <= H <= 255  (8 bits) not 256 due to WD1010 quirk
	1 <= S <= 63   (6 Bits) not 64 due to WD1010 quirk
	Returns address as c, h, s tuple :
	0 <= c <= 1023 (10 bits) modulo C
	0 <= h <= 255  (8 bits) modulo H
	1 <= s <= 63   (6 Bits) not 64 due to WD1010 quirk
	*/


	if (C < 1 || H < 1 || S < 1 || C>1024 || H>255 || S>63)
		printf("Invalid (C,H,S) geometry: (%d,%d,%d)", C, H, S);

	int t, s = lba % S;
	s += 1; // tracks, sector offset
	int c, h = t % H;

	if (c >= C)
		printf("Unaddressable lba value: %d for (%d,%d,%d) geometry.", lba, C, H, S);
	return (c, h, s);
}

int lba(int c, int h, int s, int C = 1024, int H = 255, int S = 63) {
	/*
	'C', 'H', 'S' specify geometry as for function 'chs'.
	'c', 'h', 's' address a sector in this geometry.
	*/

	if (C < 1 || H < 1 || S < 1 || C>1024 || H>255 || S>63)
		printf("Invalid (C,H,S) geometry: (%d,%d,%d)", C, H, S);

	if (c < 0 || h < 0 || s<1 || c >= C || h >= H || s>S)
		printf("Unaddressable (c,h,s) value: (%d,%d,%d) for (%d,%d,%d) geometry.", c, h, s, C, H, S);



	return (c*H + h)*S + (s - 1);
}

void hw_ide_write(struct hw_ide* hw_ide) {
	if (hw_ide->data[7] == 0b00001000) {

		hw_ide->save = 1;

		hw_ide->gambi_ide_total = hw_ide->data[2];

		unsigned long sec_address_lba = hw_ide->data[3];
		sec_address_lba = sec_address_lba | ((unsigned long)hw_ide->data[4]) << 8;
		sec_address_lba = sec_address_lba | ((unsigned long)hw_ide->data[5]) << 16;
		sec_address_lba = sec_address_lba | ((unsigned long)(hw_ide->data[6] & 0b00001111)) << 24;

		unsigned long sec_address_byte = sec_address_lba * hw_ide->lba_size;

		if (sec_address_byte < Z80CPM_IDE_MEMORY_SIZE) {
			hw_ide->memory[sec_address_byte + hw_ide->gambi_ide_read] = hw_ide->data[0];

			hw_ide->gambi_ide_read++;

			if (hw_ide->gambi_ide_read >= hw_ide->gambi_ide_total * hw_ide->lba_size)
			{
				hw_ide->data[7] = 0x00;
				hw_ide_reset(hw_ide);

				hw_ide_save_disk(hw_ide->memory);
			}
		}
		else {
			hw_ide->data[7] = 0x34;
			hw_ide_reset(hw_ide);
		}
	}

}


/*
_IDE_R0.equ _IDE_BASE + 0; DATA PORT
_IDE_R1.equ _IDE_BASE + 1; READ: ERROR CODE, WRITE : FEATURE
_IDE_R2.equ _IDE_BASE + 2; NUMBER OF SECTORS TO TRANSFER
_IDE_R3.equ _IDE_BASE + 3; SECTOR ADDRESS LBA 0[0:7]
_IDE_R4.equ _IDE_BASE + 4; SECTOR ADDRESS LBA 1[8:15]
_IDE_R5.equ _IDE_BASE + 5; SECTOR ADDRESS LBA 2[16:23]
_IDE_R6.equ _IDE_BASE + 6; SECTOR ADDRESS LBA 3[24:27 (LSB)]
_IDE_R7.equ _IDE_BASE + 7; READ: STATUS, WRITE : COMMAND
*/
void hw_ide_read(struct hw_ide* hw_ide) {

	if (hw_ide->data[7] == 0b00001000) {

		hw_ide->gambi_ide_total = hw_ide->data[2];

		unsigned long sec_address_lba = hw_ide->data[3];
		sec_address_lba = sec_address_lba | ((unsigned long)hw_ide->data[4]) << 8;
		sec_address_lba = sec_address_lba | ((unsigned long)hw_ide->data[5]) << 16;
		sec_address_lba = sec_address_lba | ((unsigned long)(hw_ide->data[6] & 0b00001111)) << 24;

		unsigned long sec_address_byte = sec_address_lba * hw_ide->lba_size;

		if (sec_address_byte < Z80CPM_IDE_MEMORY_SIZE) {
			hw_ide->data[0] = hw_ide->memory[sec_address_byte + hw_ide->gambi_ide_read];

			hw_ide->gambi_ide_read++;

			if (hw_ide->gambi_ide_read >= hw_ide->gambi_ide_total * hw_ide->lba_size)
			{
				hw_ide->data[7] = 0x00;
				hw_ide_reset(hw_ide);
			}
		}
		else {
			hw_ide->data[7] = 0x24;
			hw_ide_reset(hw_ide);
		}
	}

}



void hw_ide_save_disk(unsigned char *data) {
	FILE *file = fopen("data.dsk", "wb");
	if (file != NULL) {
		fwrite(data, sizeof(unsigned char), Z80CPM_IDE_MEMORY_SIZE, file);
		fclose(file);
	}
}

void hw_ide_load_disk(unsigned char *data) {
	FILE *file = fopen("data.dsk", "rb");
	if (file != NULL) {
		fread(data, sizeof(unsigned char), Z80CPM_IDE_MEMORY_SIZE, file);
		fclose(file);
	}
}




void hw_ide_print(struct hw_ide* hw_ide, char *dir, int changed, char *print) {

	int i = 0;
	sprintf(print, ">>> IDE [%s]: ", dir);
	for (i = 0; i < 7; i++) {

		if (changed == i)
			sprintf(print + strlen(print), "[%02x(%d)", hw_ide->data[i], hw_ide->data[i]);
		else if (changed == i - 1)
			sprintf(print + strlen(print), "]%02x(%d)", hw_ide->data[i], hw_ide->data[i]);
		else
			sprintf(print + strlen(print), " %02x(%d)", hw_ide->data[i], hw_ide->data[i]);
	}

	if (changed == i)
		sprintf(print + strlen(print), "[%02x(%d)", hw_ide->data[i], hw_ide->data[i]);
	else if (changed == i - 1)
		sprintf(print + strlen(print), "]%02x(%d)", hw_ide->data[i], hw_ide->data[i]);
	else
		sprintf(print + strlen(print), " %02x(%d)", hw_ide->data[i], hw_ide->data[i]);

	if (changed == i)
		sprintf(print + strlen(print), "]\n");
	else
		sprintf(print + strlen(print), "\n");

}