//
// hw_web.h
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
#ifndef HWWEB_H
#define HWWEB_H

#include <queue>

#include "queue_ll.h"

#if defined(__linux__) || defined(__MINGW32__)
#include <sys/socket.h> 
#include <arpa/inet.h>
#else

#include <winsock2.h>
#include <ws2tcpip.h>

// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


#endif

#include <string>
using namespace std;

struct hw_web_client {

	int running;
	int index;
#ifdef _MSC_VER    
	SOCKET *client;
#else
	int *client;
#endif
	queue<unsigned char>* tty_in;
	Queue* web_out;

};

class HW_WEB {

public:


	std::string currentline;

	struct hw_web_client clients[10];

	struct net_data {
		char data;
	};

	HW_WEB() {
		this->currentline = "";
	}
	//void init(SOL1_CPU& sol1_cpu, struct hw_uart *hw_uart);
	void new_char(char c);
	void start_server(queue<unsigned char>* tty_in);

};
#endif