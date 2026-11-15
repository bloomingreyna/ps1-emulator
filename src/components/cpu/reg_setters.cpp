#include <cassert>

#include "components/cpu.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    assert(index < 32);
    if (index != 0) { gprs[index] = value; }
}

void cpu::set_pc(uint32_t value) { pc = value; }
