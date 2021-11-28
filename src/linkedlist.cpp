//
// linked_list.cpp
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
#include "linkedlist.h"

Linked_List* ll_create(void)
{
    return NULL;
}


Linked_List* ll_insert (Linked_List* ll, void* info)
{
    Linked_List* _new = (Linked_List*) malloc(sizeof(Linked_List));
	_new->info = info;
	_new->next = ll;
    return _new;
}


Linked_List* ll_insert_sorted (Linked_List* ll, void* info, int(*cmp)(void *, void *))
{
    Linked_List* _new;
    Linked_List* a = NULL;
    Linked_List* p = ll; 
    
    while (p != NULL && cmp(p->info, info) < 0){
        a = p; 
        p = p->next;
    }
    
    
    _new = (Linked_List*) malloc(sizeof(Linked_List));
    _new->info = info;
    if (a == NULL){
        _new->next = ll; 
        ll = _new;
    } else {
        _new->next = a->next;
        a->next = _new;
    }
    return ll;
}


Linked_List* ll_remove_first(Linked_List* ll)
{
    Linked_List* p = ll; 

    ll = p->next;
    free(p);
    return ll;
}

Linked_List* ll_remove(Linked_List* ll, void* info, int(*cmp)(void *, void *))
{
    Linked_List* a = NULL; 
    Linked_List* p = ll; 
    
    while (p != NULL && cmp(p->info, info) != 0) {
        a = p;
        p = p->next;
    }
    
    if (p == NULL)
        return ll;
    
    if (a == NULL)
        ll = p->next; 
    else
        a->next = p->next;
    free(p);
    return ll;
}


void ll_print(Linked_List* ll, void(*print)(void *))
{
    Linked_List* p;
    for (p = ll; p != NULL; p = p->next){
        print(p->info);
        //sprintf("----------\n");
    }
}


Linked_List* ll_find(Linked_List* ll, void* info, int(*cmp)(void *, void *))
{
    Linked_List* p;
    for (p = ll; p != NULL; p = p-> next)
    {
        if (cmp(p->info, info) == 0)
            return p;
    }
    return NULL;
}



int ll_equal(Linked_List* ll1, Linked_List* ll2, int(*cmp)(void *, void *)) {
    Linked_List* p1; 
    Linked_List* p2; 
    for (p1=ll1, p2=ll2; p1 != NULL && p2 != NULL;
                                    p1 = p1->next, p2 = p2->next) {
        if (cmp(p1->info, p2->info) != 0)
            return 0;
    }
    if (p1 == p2)
        return 1;
    else
        return 0;
}


int ll_empty(Linked_List* ll)
{
    if (ll == NULL)
        return 1;
    else
        return 0;
}



void ll_free(Linked_List* ll, void(*ffree)(void *))
{
    Linked_List* p = ll;
    Linked_List* t;
    while (p != NULL)
    {
        t = p->next; 
        ffree(p->info);
        free(p);
        p = t; 
    }
}


int ll_size(Linked_List* ll)
{
    Linked_List* p = ll;
    int count = 0;
    while (p != NULL)
    {
        p = p->next;
        count++;
    }
    return count;
}