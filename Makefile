INCLUDES= -I ./include
FLAGS = -O3 -std=c++11
#FLAGS2 = -g

OBJECTS=./build/utils.o ./build/hw_tty.o  ./build/queue_ll.o ./build/linkedlist.o ./build/hw_web.o ./build/hw_ide.o ./build/tasm_opcode.o ./build/z80cpm_memory.o ./build/z80cpm_keyboard.o ./build/z80cpm_screen.o  ./build/z80.o

all: ${OBJECTS} 
	gcc ${FLAGS} ${INCLUDES} ./src/main.cpp ${OBJECTS} -L ./lib -lstdc++ -lm -lncurses -pthread -o ./bin/main.exe	

./build/hw_tty.o:src/hw_tty.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/hw_tty.cpp -c -o ./build/hw_tty.o

./build/hw_web.o:src/hw_web.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/hw_web.cpp -c -o ./build/hw_web.o
    
	
./build/linkedlist.o:src/linkedlist.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/linkedlist.cpp -c -o ./build/linkedlist.o

./build/queue_ll.o:src/queue_ll.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/queue_ll.cpp -c -o ./build/queue_ll.o

./build/hw_ide.o:src/hw_ide.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/hw_ide.cpp -c -o ./build/hw_ide.o
    
    
./build/z80cpm_memory.o:src/z80cpm_memory.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80cpm_memory.cpp -c -o ./build/z80cpm_memory.o
	
./build/z80cpm_keyboard.o:src/z80cpm_keyboard.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80cpm_keyboard.cpp -c -o ./build/z80cpm_keyboard.o

./build/z80cpm_screen.o:src/z80cpm_screen.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80cpm_screen.cpp -c -o ./build/z80cpm_screen.o	
	
./build/z80.o:src/z80.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80.cpp -c -o ./build/z80.o

./build/tasm_opcode.o:src/tasm_opcode.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/tasm_opcode.cpp -c -o ./build/tasm_opcode.o

./build/utils.o:src/utils.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/utils.cpp -c -o ./build/utils.o


clean:
	rm build/* 
	rm bin/main

