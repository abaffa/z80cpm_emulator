#include "z80.h"
#include "z80cpm_keyboard.h"
#include "z80cpm_memory.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <chrono>


#ifdef __MINGW32__
#include <time.h>
#include <pthread.h> 
#endif

#if defined(__linux__) || defined(__MINGW32__)
#include <fcntl.h>
#else
#include <mutex> 
#endif


using namespace std::chrono;

const unsigned int keyboard_map[Z80CPM_TOTAL_KEYS] = {
	(int)'1', (int)'2', (int)'3', (int)'4', (int)'5', (int)'6', (int)'7', (int)'8', (int)'9', (int)'0',
	(int)'q', (int)'w', (int)'e', (int)'r', (int)'t', (int)'y', (int)'u', (int)'i', (int)'o', (int)'p',
	(int)'a', (int)'s', (int)'d', (int)'f', (int)'g', (int)'h', (int)'j', (int)'k', (int)'l', (int)'\n',
	(int)'T', (int)'z', (int)'x', (int)'c', (int)'v', (int)'b', (int)'n', (int)'m', (int)'.', (int)' ',
	(int)'E'
};

typedef enum zx_keyboard {
	zxkey_n1, zxkey_n2, zxkey_n3, zxkey_n4, zxkey_n5, zxkey_n6, zxkey_n7, zxkey_n8, zxkey_n9, zxkey_n0,
	zxkey_q, zxkey_w, zxkey_e, zxkey_r, zxkey_t, zxkey_y, zxkey_u, zxkey_i, zxkey_o, zxkey_p,
	zxkey_a, zxkey_s, zxkey_d, zxkey_f, zxkey_g, zxkey_h, zxkey_j, zxkey_k, zxkey_l, zxkey_ret,
	zxkey_shift, zxkey_z, zxkey_x, zxkey_c, zxkey_v, zxkey_b, zxkey_n, zxkey_m, zxkey_period, zxkey_space,
	zxkey_backspace
} ZX_Keyboard;


int show_debug = 0;
char state = 0;
unsigned short mem_offset = 0x4000;
int mem_follow = 0;

#ifdef _MSC_VER    
mutex mtx_out;
condition_variable cv_out;

#else
pthread_mutex_t mtx_out;
#endif


void cls(HANDLE hConsole)
{
	COORD coordScreen = { 0, 0 };    // home for the cursor
	DWORD cCharsWritten;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD dwConSize;

	// Get the number of character cells in the current buffer.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

	// Fill the entire screen with blanks.
	if (!FillConsoleOutputCharacter(hConsole,       // Handle to console screen buffer
		(TCHAR)' ',     // Character to write to the buffer
		dwConSize,      // Number of cells to write
		coordScreen,    // Coordinates of first cell
		&cCharsWritten)) // Receive number of characters written
	{
		return;
	}

	// Get the current text attribute.
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		return;
	}

	// Set the buffer's attributes accordingly.
	if (!FillConsoleOutputAttribute(hConsole,        // Handle to console screen buffer
		csbi.wAttributes, // Character attributes to use
		dwConSize,       // Number of cells to set attribute
		coordScreen,     // Coordinates of first cell
		&cCharsWritten))  // Receive number of characters written
	{
		return;
	}

	// Put the cursor at its home coordinates.
	SetConsoleCursorPosition(hConsole, coordScreen);
}

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 


void cpu_exec(Z80& z80, struct z80cpm_memory* z80cpm_memory) {
	z80.z80_exec(z80cpm_memory);
}

#define LSB(w) ((w) & 0xff)
#define MSB(w) (((w) >> 8) & 0xff)
#define WORD(l, h) (((h)<<8) | (l))
void cpu_print(Z80& z80, struct z80cpm_memory* z80cpm_memory) {

	printf("\t ""%c%c%c%c%c%c%c%c""\n", BYTE_TO_BINARY(MSB(z80.registers.AF)));

	printf("  AF  |  BC  |  DE  |  HL  || S | Z | H | P | V | N | C |\n");
	printf(" %04x |", z80.registers.AF);
	printf(" %04x |", z80.registers.BC);
	printf(" %04x |", z80.registers.DE);
	printf(" %04x ||", z80.registers.HL);
	printf(" %01x |", (z80.registers.AF & S_FLAG) >> 7);
	printf(" %01x |", (z80.registers.AF & Z_FLAG) >> 6);
	printf(" %01x |", (z80.registers.AF & H_FLAG) >> 4);
	printf(" %01x |", (z80.registers.AF & P_FLAG) >> 2);
	printf(" %01x |", (z80.registers.AF & V_FLAG) >> 2);
	printf(" %01x |", (z80.registers.AF & N_FLAG) >> 1);
	printf(" %01x |", (z80.registers.AF & C_FLAG));
	printf("FLAGS ""%c%c%c%c%c%c%c%c", BYTE_TO_BINARY(LSB(z80.registers.AF)));
	printf("\n\n");

	printf("  AF' |  BC' |  DE' |  HL' ||  PC  |  SP  ||  IX  |  IY  || I  | R  |\n");
	printf(" %04x |", z80.registers.AFl);
	printf(" %04x |", z80.registers.BCl);
	printf(" %04x |", z80.registers.DEl);
	printf(" %04x ||", z80.registers.HLl);
	printf(" %04x |", z80.registers.PC);
	printf(" %04x ||", z80.registers.SP);
	printf(" %04x |", z80.registers.IX);
	printf(" %04x ||", z80.registers.IY);
	printf(" %02x |", z80.registers.I);
	printf(" %02x |", z80.registers.R);
	printf("\n\n");
	printf("IFF ""%c%c%c%c%c%c%c%c", BYTE_TO_BINARY(z80.registers.IFF));
	printf("\n\n");

	if (mem_follow)
		mem_offset = (z80.registers.PC / 0x10) * 0x10;

	int i = 0;
	printf("offset: %04x\n", mem_offset);
	printf("        ");
	for (i = 0; i < 16; i++)
		printf("%02x ", i);
	printf("\n\n %04x ", mem_offset);

	for (i = 0 + mem_offset; i < 256 + mem_offset; i++) {
		if (i % 16 == 0)
			if (z80.registers.PC == i)
				printf(" #");
			else
				printf("  ");
		if (z80.registers.PC == i || z80.registers.PC - 1 == i)
			printf("%02x#", z80.RdZ80(z80cpm_memory, i));
		else
			printf("%02x ", z80.RdZ80(z80cpm_memory, i));

		if ((i + 1) % 16 == 0 && i < 255 + mem_offset)
			printf("\n %04x ", i + 1);
	}
	printf("\n\n");
	printf("Stack:");
	for (i = 0; i < 16; i += 2) {
		if (i % 2 == 0) printf("  ");
		printf("%02x", z80.RdZ80(z80cpm_memory, z80.registers.SP + i + 1));
		printf("%02x", z80.RdZ80(z80cpm_memory, z80.registers.SP + i));
	}

	printf("\n\n");

}





int do_steps = 0;

#ifdef __MINGW32__
void *run_thread(void *vargp)
#elif _MSC_VER        
DWORD WINAPI run_thread(LPVOID vargp)
#endif
{

	Z80& z80 = *reinterpret_cast<Z80*>(vargp);
	struct z80cpm_memory *z80cpm_memory = z80.z80cpm_memory;
	queue<unsigned char> *keyboard_queue = &z80.keyboard_queue;

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hConsole);

	double deltaTime = 0;
	double frame = 0;
	double ide = 0;
	double keyboard = 0;
	double cpu_clk = 0;
	double cpu = 0;

	if (show_debug) {
		printf("0.0fMHz - 0\n");
		printf("Opcode: \n\n\n");
		cpu_print(z80, z80cpm_memory);
	}
	int iii = 0;
	double speed = 3.0769230769231E-20;
	//1.25E-7
	//3.0769230769231E-7;

	do_steps = 0;
	int step = 0;
	
	int wait = 0;

	int do_breakpoint = 0;
	unsigned char bp_opcode = 0xed;
	unsigned char bp_opcode2 = 0x78;
	unsigned short breakpoint = 0x65B; //0x194; //0x168; //0x0154; 143 // 141

#ifdef __MINGW32__
	struct timespec tstart = { 0,0 }, tend = { 0,0 };
#elif _MSC_VER    
	auto tstart = high_resolution_clock::now();
	auto tend = high_resolution_clock::now();
#endif 
	while (1) {

		/*
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();

		deltaTime = (double)((NOW - LAST)*1000 / (double)SDL_GetPerformanceFrequency() );
		*/


#ifdef __MINGW32__
		clock_gettime(CLOCK_MONOTONIC, &tend);
		deltaTime = ((double)tend.tv_sec + 1.0e-9*tend.tv_nsec) - ((double)tstart.tv_sec + 1.0e-9*tstart.tv_nsec);
		clock_gettime(CLOCK_MONOTONIC, &tstart);
#elif _MSC_VER        
		tend = high_resolution_clock::now();
		deltaTime = duration_cast<nanoseconds>(tend - tstart).count() * 1e-9;
		tstart = high_resolution_clock::now();
#endif 

		frame += deltaTime;
		keyboard += deltaTime;
		ide += deltaTime;
		cpu += deltaTime;
		cpu_clk += deltaTime;

		

		if ((z80.registers.IFF & IFF_HALT) == 0x0 &&
			((!do_steps && cpu >= speed) || (do_steps && step))) {



	//		if (keyboard >= 0.0005) {

				if (wait == 0 && do_steps == 0 && z80.IRequest == INT_NONE && z80.PORT_0002h == 0xFF && !(z80.registers.IFF & IFF_EI) && (z80.registers.IFF & IFF_1) && (z80.registers.IFF & IFF_2) && !keyboard_queue->empty()) {


#ifdef _MSC_VER    
					std::unique_lock<std::mutex> lock(mtx_out);
#else
					pthread_mutex_lock(&mtx_out);
#endif

					int key = keyboard_queue->front();
					keyboard_queue->pop();

#ifdef _MSC_VER    
					cv_out.notify_all();
#else
					pthread_mutex_unlock(&mtx_out);
#endif


					//if (key != (int)'7' && key != (int)'8' && key != (int)'9') {


					z80.registers.IFF &= ~IFF_2;
					z80.PORT_0002h = key;
					z80.IRequest = z80.keyboard_int;
					//z80.registers.IFF &= ~IFF_1;
					//z80.registers.IFF |= IFF_EI;
					//IntZ80(z80, z80cpm_memory->memory, 0x60);
					wait = 1;
				}
				else if (wait < 700 && wait > 0 && do_steps == 0 && z80.IRequest == INT_NONE && z80.PORT_0002h == 0xFF && !(z80.registers.IFF & IFF_EI) && (z80.registers.IFF & IFF_1) && (z80.registers.IFF & IFF_2) && !keyboard_queue->empty())
					wait++;
				else if (do_steps == 0 && z80.IRequest == INT_NONE && z80.PORT_0002h == 0xFF && !(z80.registers.IFF & IFF_EI) && (z80.registers.IFF & IFF_1) && (z80.registers.IFF & IFF_2) && !keyboard_queue->empty())
					wait = 0;

				keyboard = 0;
//			}


			cpu_exec(z80, z80cpm_memory); iii++;
			cpu = 0;

			step = 0;
			//if(RdZ80(z80,0x4042) == 0x1c)
			//if(do_breakpoint && z80.registers.HL ==0x4042)
			//  do_steps = 1;


			if (do_breakpoint && z80.registers.PC == breakpoint)
				do_steps = 1;

			//if(do_breakpoint && z80->RdZ80(RdZ80(z80, z80.registers.PC) == bp_opcode
			//&& z80->RdZ80(RdZ80(z80, z80.registers.PC+1) == bp_opcode2)
			//  do_steps = 1;

		}
		else if (z80.registers.IFF & IFF_HALT) {
			cpu = 0;
			iii++;
		}
			   		 

		if (frame >= 0.1) {
			/*
		if (key == (int)'b') {
			do_breakpoint = !do_breakpoint;
		}

		if (key == (int)'s') {
			do_steps = !do_steps;
		}

		if (key == (int)'r') {
			do_steps = 0;
		}

		if (key == (int)'n') {
			step = 1;
		}

		if (key == (int)'2') {
			if (mem_offset + 0x10 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x10;
		}
		if (key == (int)'1') {
			if (mem_offset - 0x10 > 0)
				mem_offset -= 0x10;
		}
		if (key == (int)'3') {
			if (mem_offset + 0x100 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x100;
		}
		if (key == (int)'4') {
			if (mem_offset - 0x100 > 0)
				mem_offset -= 0x100;
		}
		if (key == (int)'5') {
			if (mem_offset + 0x1000 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x1000;
		}
		if (key == (int)'6') {
			if (mem_offset - 0x1000 > 0)
				mem_offset -= 0x1000;
		}
		if (key == (int)'7') {
			speed /= 10;
		}
		if (key == (int)'8') {
			if (speed < 1)
				speed *= 10;
			else if (speed > 1)
				speed += 1;

			if (speed > 2)
				speed = 2;
		}
		if (key == (int)'9') {
			mem_follow = !mem_follow;
		}

		if (key == (int)'0')
			return NULL;
			*/


			//cls(hConsole);

			if (show_debug) {
				COORD pos = { 0, 0 };
				SetConsoleCursorPosition(hConsole, pos);
				printf("                                                                                                                                                      \r\n");
				printf("                                                                                                                                                      \n");
				printf("                                                                                                                                                      \n");
				SetConsoleCursorPosition(hConsole, pos);
				printf("%.3fMHz - %g\n", ((float)iii) / 1000000, speed);
				printf("%s", z80.last_op_desc);
				cpu_print(z80, z80cpm_memory);
			}
			frame = 0;


		}

		if (z80.registers.IFF & IFF_HALT) {
			//printf("%s", z80.last_op_desc);
			//printf("HALT");
			//return;


			//do_steps = 0;
			//do_steps = 1;
			z80.IntZ80(z80cpm_memory, INT_IRQ); iii++;
			z80.registers.IFF |= IFF_1;
			z80.IntZ80(z80cpm_memory, INT_IRQ);
		}


		if (cpu_clk >= 1) {
			iii = 0;
			cpu_clk = 0;
		}




		if (ide >= 10) {
			if (z80.hw_ide.save == 1) {
				hw_ide_save_disk(z80.hw_ide.memory);
				z80.hw_ide.save = 0;
			}

			ide = 0;
		}
	}

	return NULL;
}


int main(int argc, char** argv)
{

	const char* filename;
	if (argc < 2)
	{
		printf("Loading Default Rom\n");
		//return -1;
		filename = "rom.bin";
	}
	else
		filename = argv[1];

	printf("The filename to load is: %s\n", filename);

	FILE* f = fopen(filename, "rb");
	if (!f)
	{
		printf("Failed to open the file\n");
		printf("Press any key to continue");
		getch();
		return -1;
	}

	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buf = (char*)malloc(size * sizeof(char));

	int res = fread(buf, size, 1, f);
	if (res != 1)
	{
		printf("Failed to read from file");
		return -1;
	}


	struct z80cpm_keyboard z80cpm_keyboard;
	struct z80cpm_memory z80cpm_memory;
	Z80 z80;
	z80.z80_init();

	///////////////////////////////////////////////////////////////////////////
	z80cpm_memory.memory = (unsigned char*)malloc(Z80CPM_MEMORY_SIZE * sizeof(unsigned char));
	z80cpm_memory.rom = (unsigned char*)malloc(Z80CPM_MEMORY_SIZE * sizeof(unsigned char));
	//memcpy(z80->RdZ80(memory.memory, z80_default_character_set, sizeof(z80_default_character_set));

	int j = 0;
	for (j = 0; j < Z80CPM_MEMORY_SIZE; j++) {
		z80cpm_memory.memory[j] = 0x00;
		z80cpm_memory.rom[j] = 0x00;
	}
	z80cpm_memory.rom_disabled = 0;

	//assert(size + Z80_PROGRAM_LOAD_ADDRESS < Z80_MEMORY_SIZE);
	//memcpy(&z80->RdZ80(memory.z80cpm_memory->memory[Z80_PROGRAM_LOAD_ADDRESS], buf, size);

	//memcpy(z80->RdZ80(memory.memory, buf, size);
	memcpy(&z80cpm_memory.rom[0], buf, size);
	///////////////////////////////////////////////////////////////////////////

	z80.z80_reset();

	z80cpm_keyboard_set_map(&z80cpm_keyboard, keyboard_map);


	z80.z80cpm_memory = &z80cpm_memory;


#ifdef __MINGW32__
	pthread_t tid;
	pthread_create(&tid, NULL, run_thread, (void *)&z80cpm_computer);
#elif _MSC_VER        
	DWORD tid;
	HANDLE myHandle = CreateThread(0, 0, run_thread, &z80, 0, &tid);
#endif




	while (1) {
		//if (kbhit()) {
		int key = getch();
		if (key == '`') {
			printf("\n");
			printf("<< COLD RESET >>\n");
			z80.registers.PC = 0;
			z80cpm_memory.rom_disabled = 0;
		}
		else {
#ifdef _MSC_VER    
			std::unique_lock<std::mutex> lock(mtx_out);
#else
			pthread_mutex_lock(&mtx_out);
#endif

			z80.keyboard_queue.push(key);

#ifdef _MSC_VER    
			cv_out.notify_all();
#else
			pthread_mutex_unlock(&mtx_out);
#endif


		}
		//}

		/*
		if (key == (int)'2') {
			if (mem_offset + 0x10 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x10;
		}
		if (key == (int)'1') {
			if (mem_offset - 0x10 > 0)
				mem_offset -= 0x10;
		}
		if (key == (int)'3') {
			if (mem_offset + 0x100 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x100;
		}
		if (key == (int)'4') {
			if (mem_offset - 0x100 > 0)
				mem_offset -= 0x100;
		}
		if (key == (int)'5') {
			if (mem_offset + 0x1000 < Z80CPM_MEMORY_SIZE)
				mem_offset += 0x1000;
		}
		if (key == (int)'6') {
			if (mem_offset - 0x1000 > 0)
				mem_offset -= 0x1000;
		}

		if (key == (int)'9') {
			mem_follow = !mem_follow;
		}

		if (key == (int)'0')
			return NULL;
			*/
	}

out:

	return 0;
}
