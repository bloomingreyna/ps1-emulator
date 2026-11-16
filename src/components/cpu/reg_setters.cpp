#include <cassert>

#include "components/cpu.h"
#include "components/mult_div_unit.h"

void cpu::set_gpr(std::size_t index, uint32_t value)
{
    assert(index < 32);
    if (index != 0) { gprs[index] = value; }
}

void cpu::set_pc(uint32_t value) { pc = value; }
void cpu::set_hi(uint32_t value) { md_unit.set_hi(value); }
void cpu::set_lo(uint32_t value) { md_unit.set_lo(value); }

void mult_div_unit::set_hi(uint32_t value) { hi = value; }
void mult_div_unit::set_lo(uint32_t value) { lo = value; }
