cmake_minimum_required(VERSION 3.18)
project(ps1-emu)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(blps1
    src/main.cpp
    src/components/cpu/tick.cpp
    src/components/cpu/pc_change.cpp
    src/components/cpu/load.cpp
    src/components/cpu/store.cpp
    src/components/cpu/reg_getters.cpp
    src/components/cpu/reg_setters.cpp
    src/components/system/memory_accesses.cpp
    src/instructions/opcode.cpp
    src/instructions/add.cpp
    src/instructions/bitwise.cpp
    src/instructions/branch.cpp
    src/instructions/divide.cpp
    src/instructions/jump.cpp
    src/instructions/load.cpp
    src/instructions/move.cpp
    src/instructions/multiply.cpp
    src/instructions/set_on.cpp
    src/instructions/special_dispatch.cpp
    src/instructions/store.cpp
    src/instructions/subtract.cpp
)

target_include_directories(blps1 PRIVATE include)
