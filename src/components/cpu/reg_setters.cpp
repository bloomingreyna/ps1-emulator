#include <cassert>

#include "components/cpu.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    assert(index < 32);
    if (index != 0) { gprs[index] = value; }
    write_occurred = true;
    written_index_priority = index;
}

void cpu::set_pc(uint32_t value) { pc = value; }
void cpu::set_hi(uint32_t value) { hi = value; }
void cpu::set_lo(uint32_t value) { lo = value; }
