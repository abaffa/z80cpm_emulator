//
// tasm_opcode.cpp
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
#include "tasm_opcode.h"

Tasm_Opcode::Tasm_Opcode(string opcode, string desc, int size) {
	this->opcode = opcode;
	this->desc = desc;
	this->size = size;
}


void save_to_log(char *s, FILE *fa, char *str)
{

	//FILE *fa = fopen("File1.txt", "a");
	if (fa == NULL)
	{
		if (s == NULL)
			printf("can not open target file\n");
		else
			sprintf(s, "can not open target file\n");
		exit(1);
	}

	fprintf(fa, "%s", str);
	fflush(fa);
	//fputc(str, fa);

//fclose(fa);

}
