#include <cassert>

#include "components/cpu.h"

uint32_t cpu::get_gpr(std::size_t index)
{
    assert(index < 32);
    if (index == 0) { return 0; }
    return gprs[index];
}

uint32_t cpu::get_pc() { return pc; }
