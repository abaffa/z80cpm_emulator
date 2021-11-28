//
// queue_ll.h
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
#ifndef DEQUEUE_H
#define DEQUEUE_H

#include "linkedlist.h"

typedef struct queue_ll Queue;


Queue* queue_create (void);

void queue_insert (Queue* f, void* info);

void* queue_remove (Queue* f);

int queue_empty (Queue* f);

void queue_free (Queue* f, void (* ffree)(void *));

void queue_print (Queue* f, void (* fprint)(void *));

#endif