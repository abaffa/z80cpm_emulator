//
// linked_list.h
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
typedef struct linked_list
{
    void* info;
    struct linked_list *next;
} Linked_List;


Linked_List* ll_create (void);

Linked_List* ll_insert (Linked_List* ll, void* info);

Linked_List* ll_insert_sorted (Linked_List* ll, void* info, int (*cmp)(void *, void *));

Linked_List* ll_remove_first (Linked_List* ll);

Linked_List* ll_remove (Linked_List* ll, void* info, int (*cmp)(void *, void *));

void ll_print (Linked_List* ll, void (*print)(void *));

Linked_List* ll_find (Linked_List* ll, void* info, int (*cmp)(void *, void *));

int ll_equal (Linked_List* ll1, Linked_List* ll2, int (*cmp)(void *, void *));

int ll_empty (Linked_List* ll);

void ll_free (Linked_List* ll, void (* ffree)(void *));

int ll_size(Linked_List* ll);