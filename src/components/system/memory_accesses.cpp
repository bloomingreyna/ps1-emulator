#include "components/ps1.h"

bool operator<=(uint32_t lhs, memory_map rhs) { return lhs <= static_cast<uint32_t>(rhs); }
bool operator>=(uint32_t lhs, memory_map rhs) { return lhs >= static_cast<uint32_t>(rhs); }

bool in_user_memory(uint32_t addr)
{
    return (
        (addr >= memory_map::USER_MEM_START && addr <= memory_map::USER_MEM_END) ||
        (addr >= memory_map::KSEG0_START && addr <= memory_map::KSEG0_END) ||
        (addr >= memory_map::KSEG1_START && addr <= memory_map::KSEG1_END)
    );
}

uint8_t ps1::read_memory(uint32_t addr)
{
    if (in_user_memory(addr))
    {
        return system_ram[addr & 0x1FFFFFFF];
    }
    return 0;
}
