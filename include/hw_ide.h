//
// hw_ide.h
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
#ifndef HWIDE_H
#define HWIDE_H

#include <stdio.h>
#include "config.h"


struct hw_ide {

	int gambi_ide_total;
	int gambi_ide_read;

	int lba_size;

	unsigned char data[8];

	unsigned char* memory;

	int save;
};

void hw_ide_init(struct hw_ide* hw_ide);
void hw_ide_reset(struct hw_ide* hw_ide);

void hw_ide_read(struct hw_ide* hw_ide);
void hw_ide_write(struct hw_ide* hw_ide);

void hw_ide_print(struct hw_ide* hw_ide, char *dir, int changed, char *print);


void hw_ide_save_disk(unsigned char *data);
void hw_ide_load_disk(unsigned char *data);
#endif
