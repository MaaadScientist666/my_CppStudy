cmake_minimum_required(VERSION 4.3)
project(address_books)

set(CMAKE_CXX_STANDARD 20)

add_executable(address_books main.cpp)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")