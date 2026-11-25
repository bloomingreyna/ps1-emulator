#pragma once

#include <cstdint>
#include <vector>

#include "components/cpu.h"

enum class memory_map : uint32_t
{
    KERNEL_START = 0x00000000, KERNEL_END = 0x0000FFFF,
    USER_MEM_START = 0x00010000, USER_MEM_END = 0x001FFFFF,
    PARALLEL_PORT_START = 0x1F000000, PARALLEL_PORT_END = 0x1F00FFFF,
    SCRATCHPAD_START = 0x1F800000, SCRATCHPAD_END = 0x1F8003FF,
    HARDWARE_REGS_START = 0x1F801000, HARDWARE_REGS_END = 0x1F802FFF,
    KSEG0_START = 0x80000000, KSEG0_END = 0x801FFFFF,
    KSEG1_START = 0xA0000000, KSEG1_END = 0xA01FFFFF,
    BIOS_START = 0xBFC00000, BIOS_END = 0xBFC7FFFF
};

class ps1
{
public:
    uint8_t read_memory(uint32_t addr);
    void write_memory(uint32_t addr, uint8_t value);
private:
    void throw_bus_error_exception();

    cpu c{};
    std::vector<uint8_t> system_ram{std::vector<uint8_t>(1024 * 1024 * 2)};
};
