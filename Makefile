INCLUDES= -I ./include
FLAGS = -O3 -std=c++11
#FLAGS2 = -g

OBJECTS=./build/z80_memory.o ./build/zx80_keyboard.o ./build/zx80_screen.o  ./build/z80.o

all: ${OBJECTS} 
	gcc ${FLAGS} ${INCLUDES} ./src/test.cpp ${OBJECTS} -L ./lib -lmingw32 -lstdc++ -lSDL2main -lSDL2 -lSDL2_ttf -o ./bin/test.exe	

main: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main.cpp ${OBJECTS} -L ./lib -lmingw32 -lstdc++ -lSDL2main -lSDL2 -lSDL2_ttf -o ./bin/main.exe	

main2: ${OBJECTS}
	gcc ${FLAGS} ${INCLUDES} ./src/main2.cpp ${OBJECTS} -L ./lib -lmingw32 -lstdc++ -o ./bin/main2.exe	

./build/z80_memory.o:src/z80_memory.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80_memory.cpp -c -o ./build/z80_memory.o
	
./build/zx80_keyboard.o:src/zx80_keyboard.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/zx80_keyboard.cpp -c -o ./build/zx80_keyboard.o

./build/zx80_screen.o:src/zx80_screen.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/zx80_screen.cpp -c -o ./build/zx80_screen.o	
	
./build/z80.o:src/z80.cpp
	gcc ${FLAGS} ${INCLUDES} ./src/z80.cpp -c -o ./build/z80.o

clean:
	del build\* /q
	del bin\main.exe /q
	del bin\main2.exe /q
	del bin\test.exe /q