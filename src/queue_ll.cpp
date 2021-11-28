//
// queue_ll.cpp
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
#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

struct queue_ll {
	Linked_List* begin;
	Linked_List* end;
};

Queue* queue_create(void) {
	Queue* f = (Queue*)malloc(sizeof(Queue));
	f->begin = NULL;
	f->end = NULL;
	return f;
}


void queue_insert(Queue* f, void* info) {

	Linked_List* n = ll_insert(NULL, info);


	if (f->end != NULL)
		f->end->next = n;
	else
		f->begin = n;
	f->end = n;
}


void* queue_remove(Queue* f) {

	void* info;

	if (queue_empty(f)) {
		return NULL;
	}

	if (f->begin == NULL){
		f->end = NULL;
		return NULL;
	}
	else {
		info = f->begin->info;

		f->begin = ll_remove_first(f->begin);

		if (f->begin == NULL)
			f->end = NULL;
	}
	return info;
}


int queue_empty(Queue* f)
{
	return ll_empty(f->begin) && ll_empty(f->end);
}

void queue_free(Queue* f, void(*ffree)(void *))
{
	ll_free(f->begin, ffree);

	free(f);
}

void queue_print(Queue* f, void(*fprint)(void *))
{

	Linked_List* q = f->begin;
	while (q != NULL) {
		fprint(q->info);
		q = q->next;
	}
}