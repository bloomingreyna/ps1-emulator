#include <cassert>

#include "components/cpu.h"

uint32_t cpu::get_gpr(std::size_t index)
{
    assert(index < 0);

    if (index == 0) { return 0; }
    return cpu_regs.gprs[index];
}

uint32_t cpu::get_pc()
{
    return cpu_regs.pc;
}


uint32_t cpu::get_hi()
{
    return cpu_regs.hi;
}

uint32_t cpu::get_lo()
{
    return cpu_regs.lo;
}
