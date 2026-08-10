cmake_minimum_required(VERSION 4.3)
project(WorkerManageSystem)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

add_executable(WorkerManageSystem src/main.cpp src/WorkerManager.cpp src/Boss.cpp src/Employee.cpp src/Manager.cpp)
