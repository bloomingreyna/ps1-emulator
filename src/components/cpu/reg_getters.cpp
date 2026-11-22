#include <cstdint>

#include "components/cpu.h"

uint32_t cpu::get_gpr(std::size_t index) const
{
    if (index == 0)
    {
        return 0;
    }
    return gprs[index];
}

uint32_t cpu::get_pc() const { return pc; }
uint32_t cpu::get_hi() const { return hi; }
uint32_t cpu::get_lo() const { return lo; }
