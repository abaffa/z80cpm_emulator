//
// hw_tty.h
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
#ifndef HWTTY_H
#define HWTTY_H

#include "config.h"
#include "hw_tty_client.h"
#include <queue>

#if defined(__linux__) || defined(__MINGW32__)
#include <sys/socket.h>
#include <fcntl.h>
#else
#include <mutex> 
#include <winsock2.h>
#include <ws2tcpip.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#endif


using namespace std;




class HW_TTY {


public:

	HW_TTY_CLIENT clients[10];

	struct net_data {
		unsigned char data;
	};

	unsigned char started;
	unsigned char debug_call;
	unsigned char console;

	//void init(struct hw_uart *hw_uart);
	void start_server(queue<unsigned char> *keyboard_queue);

	queue<unsigned char> tty_in;

	void send(unsigned char b);
	unsigned char receive();

	void print(const char* s);

	void set_input(unsigned char b);

	char* gets(int max_value);
	char* getline();
	char get_char();

	HW_TTY() {
		started = 0;
		debug_call = 0;
		console = 0;
	}
};
#endif