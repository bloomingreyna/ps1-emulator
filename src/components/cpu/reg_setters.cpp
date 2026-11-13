#include <cassert>

#include "components/cpu.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    assert(index < 32);

    if (index != 0) { cpu_regs.gprs[index] = value; }
}

void cpu::set_pc(uint32_t value)
{
    cpu_regs.pc = value;
}

void cpu::set_hi(uint32_t value, unsigned int cycle_delay)
{
    cpu_regs.hi_fresh = value;
}

void cpu::set_lo(uint32_t value, unsigned int cycle_delay)
{
    cpu_regs.lo_fresh = value;
}
