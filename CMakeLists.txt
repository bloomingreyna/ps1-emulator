cmake_minimum_required(VERSION 3.18)
project(ps1-emu)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(blps1
    src/main.cpp
    src/components/cpu/execute_instruction.cpp
    src/components/cpu/mult_div_unit_getters.cpp
    src/components/cpu/mult_div_unit_setters.cpp
    src/components/cpu/mult_div_unit_ops.cpp
    src/components/cpu/reg_getters.cpp
    src/components/cpu/reg_setters.cpp
    src/instructions/opcode.cpp
    src/instructions/special_dispatch.cpp
    src/instructions/add.cpp
    src/instructions/bitwise.cpp
    src/instructions/branch.cpp
    src/instructions/divide.cpp
    src/instructions/move.cpp
    src/instructions/multiply.cpp
    src/instructions/set_on.cpp
)

target_include_directories(blps1 PRIVATE include)
