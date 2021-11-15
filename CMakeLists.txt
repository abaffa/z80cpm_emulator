cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(zx80_emul)

find_package(SDL2 CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(zx80_emul 
    src/main.cpp
    src/z80_memory.cpp
    src/z80.cpp
    src/zx80_keyboard.cpp
    src/zx80_screen.cpp
)

target_include_directories(zx80_emul PUBLIC include)

target_link_libraries(zx80_emul PRIVATE SDL2::SDL2 SDL2::SDL2main)